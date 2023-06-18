#include "main.h"
#include "math.h"

#include "Data/Dataset.h"

#define pi									((float)(3.14159265358))
#define R 									((float)(6373044.737))	//radius of the earth in meters


#define GPS_ISINPLACE_CHECK_DISTANCE		((float)(0.0000005))			//tolerance used to determinate (approximately) if the GPS is in place or not (0.000002 previous value)

//dimensions in meters
#define SECTORS_LENGTH						(20)					//this value must be higher than SECTORS_RECT_LENGTH (to avoid overlaps)
#define SECTORS_RECT_LENGTH					(5)						//going under 5 meters can be dangerous (due the GPS resolution); higher value is safer
#define SECTORS_RECT_WIDTH					(10)
#define START_LINE_LENGTH					(8)						//going under 5 meters can be dangerous (due the GPS resolution); higher value is safer //8 previous value
#define START_LINE_WIDTH					(12)
#define LAST_SECTOR_MIN_LENGTH				(10)						//to avoid a too short last sector that can create problems

#define SECTORS_CALCULATION_LAP				(0)						//lap number where are calculated sectors (0 is the first lap started)
#define START_LINE_DIRECTION_WINDOW			(80)					//max direction offset from the start line direction (used to avoid double lap trigger in tight trucks (like carpi/marzaglia)





/**
  * @brief  GPS degUnit structures definition
  */
typedef enum
{
	GPS_DEGREE      = 0x00U,
	GPS_RADIANT    	= 0x01U
} GPS_DegUnitTypedef;


/**
  * @brief  gps_point structures definition
  */
typedef struct
{
	float latitude;
	float longitude;
} gps_point;


/**
  * @brief  gps_rect structures definition
  */
typedef struct
{
	gps_point refPoint;					//point at the center of the rect
	gps_point points[4];				//vertex of the rectangle
	float direction;					//orientation of the rectangle
	float width;						//rectangle width
	float length;						//rectangle length
} gps_rect;


/**
  * @brief  sector structures definition
  */
typedef struct
{
	float lat;							//latitude of the sector's point
	float lon;							//longitude of the sector's point
	gps_rect rect;						//rectangle used to detect the sector
	float length;						//sector's length in meters
	float distance;						//sector's distance from the start-finish point
	int number;							//sector number
	int bestTime;						//best time
	int lastTime;						//last time
	int bestTimeLap;					//lap number detecting the best time
} sector;


/**
  * @brief  lap structures definition
  */
typedef struct
{
	int time;							//lap time in milliseconds
	int delay;							//time delay from fastest lap in milliseconds
	float length;						//lap length in meters
	int number;							//lap number
	int sectorTimes[1000];				//lap's sectors' times in milliseconds
	int sectorStatus[1000];				//lap's sectors' status (if 0 == OK, else there was a problem while measuring)
	int sectorDeltaFastestLap[1000];	//lap's sectors' delta time from the same sector of the fastest lap
	int sectorCounter;					//lap'sector counted
	int samples;						//samples used to measure the lap's data
} lap;


#define degToRad(deg)						(deg * pi / 180)		//DEGREE to RADIANT
#define radToDeg(rad)						(rad * 180 / pi)		//RADIANT to DEGREE

/**
  * @brief  Calculate the distance in meters from two points given in radiant coordinates
  *
  * @param  lat1 is the latitude of the starting point in RADIANT.
  * @param  lon1 is the longitude of the starting point in RADIANT.
  * @param  lat2 is the latitude of the end point in RADIANT.
  * @param  lon2 is the longitude of the point end in RADIANT.
  *
  * @note   This function use as earth radius R previously defined that is the root mean square of the earth
  *
  * @retval float value (meters)
  */
#define GPS_DISTANCE_RAD(lat1, lon1, lat2, lon2)  (R * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2)))

/**
  * @brief  Calculate the distance in meters from two points given in degree coordinates
  *
  * @param  lat1 is the latitude of the starting point in DEGREE.
  * @param  lon1 is the longitude of the starting point in DEGREE.
  * @param  lat2 is the latitude of the end point in DEGREE.
  * @param  lon2 is the longitude of the point end in DEGREE.
  *
  * @note   This function use as earth radius R previously defined that is the root mean square of the earth
  *
  * @retval float value (meters)
  */
#define GPS_DISTANCE_DEG(lat1, lon1, lat2, lon2)  (R * acos(sin(degToRad(lat1)) * sin(degToRad(lat2)) + cos(degToRad(lat1)) * cos(degToRad(lat2)) * cos(degToRad(lon1) - degToRad(lon2))))

/**
  * @brief  Calculate the direction in degree from two points given in radiant coordinates
  *
  * @param  latitude1 is the latitude of the starting point in RADIANT.
  * @param  longitude1 is the longitude of the starting point in RADIANT.
  * @param  latitude2 is the latitude of the end point in RADIANT.
  * @param  longitude2 is the longitude of the point end in RADIANT.
  *
  * @retval float value (radiant)
  */
float GPS_DIRECTION_RAD(float latitude1, float longitude1, float latitude2, float longitude2)
{
	float deltaFi = log(tan(latitude2 / 2 + pi / 4) / tan(latitude1 / 2 + pi / 4));
	float deltaLon = (longitude2 - longitude1);

	float direction12 = atan2(deltaLon, deltaFi);
	deltaLon < 0 ? direction12 = direction12 + pi : 1;

	return direction12;
}

/**
  * @brief  Calculate the direction in degree from two points given in degree coordinates
  *
  * @param  latitude1 is the latitude of the starting point in DEGREE.
  * @param  longitude1 is the longitude of the starting point in DEGREE.
  * @param  latitude2 is the latitude of the end point in DEGREE.
  * @param  longitude2 is the longitude of the point end in DEGREE.
  *
  * @retval float value (degree)
  */
float GPS_DIRECTION_DEG(float latitude1, float longitude1, float latitude2, float longitude2)
{
	latitude1 = degToRad(latitude1);
	longitude1 = degToRad(longitude1);
	latitude2 = degToRad(latitude2);
	longitude2 = degToRad(longitude2);

	float deltaFi = log(tan(latitude2 / 2 + pi / 4) / tan(latitude1 / 2 + pi / 4));
	float deltaLon = (longitude2 - longitude1);

	float direction12 = radToDeg(atan2(deltaLon, deltaFi));
	deltaLon < 0 ? direction12 = direction12 + 360 : 1;

	return direction12;
}



unsigned int GPS_lapTimer_RESET = 1;	//variable to detect the first call and to erase all the variables
float totalDistance = 0;				//total distance calculated from the GPS coordinate
float currentLapDistance = 0;			//distance from start-finish line of the current lap
float minDistance = 0;					//minimum distance between two points misused
float maxDistance = 0;					//maximum distance between two points misused
int processedSamples = 1;				//total number of samples processed (one sample = one GPS point)
int discardedSamplesFirstLap = 0;		//samples before the start-finnish line (before the first lap)
int discardedSamplesLastLap = 0;		//samples after the last pass on the start-finish line

float lapStart[2];						//lap start-finish point
int startLineStatus = 0;				//0 = to find starting point, 1 = to detect, 2 = detected
gps_rect startLine;						//start-finish line rectangle data
sector sectors[1000] __attribute__((section(".SDRAM")));					//sectors database
int sectorNumber = 0;					//number of sectors detected/created

lap laps[50] __attribute__((section(".SDRAM")));							//laps database
int lapCounter = -2;					//used as lap counter; -2 init is required to ensure the right procedure (WARNING: erasing the function the variable must be set at -2)
int fastestLapPointer = 0;				//used to detect the fastest lap in laps[] vector
int fastestLapPointerOld = 0;			//used to debounce and other
int secondFastestLapPointer = 0;		//used to detect the second fastest lap in laps[] vector (contains the previous value of fastestLapPointer)
int liveTimeDelta = 0;					//contains the live time delta between the current lap and the fastest
int lapTimeDelta = 0;					//contains the delta from the best lap of the las completed lap

uint8_t gpsLapEnabled = 0;

//descriptions at declaration
int GPS_isInPlace(float latitudeRef, float longitudeRef, float latitude, float longitude, int angleUnit);
void GPS_createRectPoints(gps_rect* rect, float latitude1, float longitude1, float latitude2, float longitude2, float width, float length, int angleUnit);
void GPS_createRect(gps_rect* rect, float latitude1, float longitude1, float direction, float width, float length, int angleUnit);
int GPS_isPointInRect(gps_rect *rect, float lat, float lon);
void GPS_lapTimerReset(void);
void GPS_lapSetStarPoint(float lat, float lon);

void GPS_CAR_DataCopy(Dataset* dataset);


void lapTimer(float lat, float lon, int samplingTime, Dataset* dataset)
{
	//general variables used in the function

	//float lat;									//input variable for the function: latitude in degree from GPS
	//float lon;									//input variable for the function: latitude in degree from GPS
	//float samplingTime;					//input variable for the function: time when the point was sampled in milliseconds

	static float latOld = 0;					//latitude of older point
	static float lonOld = 0;					//longitude of older point

	register float distance;					//distance between two points

	int lastPointTimeInterval;					//milliseconds between the sampled points
	static int pointSamplingTimeOld = 0;		//time when the old point was sampled in milliseconds



	//static variables used for lap's timing
	static int carOnStartLineOld = 0;			//used as debounce system of "carOnStartLine"
	static int lapBeginSampleNumber = 0;		//used to calculate the lap's sample's number
	static float lapDistanceOld = 0;			//used to calculate the lap distance from the total distance
	static int lapTimeStart = 0;				//contains the time when the lap started
	static int lapCounterOld = -2;				//contains the old lap number (used for debounces purpose)



	//static variables used for sector's realization
	static int sectorSamples = 0;				//used to calculate the sector's travel time
	static float sectorLength = 0;				//used to calculate the sector's length in meters
	static int sectorTimeStart = 0;				//used to find the sector's time

	static int lastSectorDetected = 0;			//used to calculate the last sector by the penultimate and the lap's starting point
	static int sectorSamplesSum = 0;			//used to calculate the last sector time (WARNING: modify the method using the time between samples)
	static int sectorRectToCalculate = 0;		//used to indicate if is needed/possible to calculate a rectangle for the sector



	//static variables used in current lap's sector detections
	static int currentSectorSamples = 0;			//used to calculate the time travel of the sector
	static int currentSectorCounter = 0;			//used to count in witch sector is the car
	static int currentSectorTime = 0;				//used to have a live time of a current sector
	static int carOnSectorPointOld = 0;				//used as debounce for "carOnSectorPoint"




	if(GPS_lapTimer_RESET != 0)
	{
		//erase all the variables

		//static general variables used in the function
		latOld = 0;
		lonOld = 0;

		//static variables used for lap's timing
		carOnStartLineOld = 0;
		lapBeginSampleNumber = 0;
		lapDistanceOld = 0;
		lapTimeStart = 0;

		//static variables used for sector's realization
		sectorSamples = 0;
		sectorLength = 0;
		sectorTimeStart = 0;
		lastSectorDetected = 0;
		sectorSamplesSum = 0;
		sectorRectToCalculate = 0;

		//static variables used in current lap's sector detections
		currentSectorSamples = 0;
		currentSectorCounter = 0;
		currentSectorTime = 0;
		carOnSectorPointOld = 0;


		//main variables used
		totalDistance = 0;
		currentLapDistance = 0;
		minDistance = 0;
		maxDistance = 0;
		processedSamples = 1;
		discardedSamplesFirstLap = 0;
		discardedSamplesLastLap = 0;

		sectorNumber = 0;
		lapCounter = -2;					//WARNIG: is crucial that the erasing value is -2
		lapCounterOld = -2;
		fastestLapPointer = 0;				//not really important to erase
		fastestLapPointerOld = 0;
		secondFastestLapPointer = 0;
		liveTimeDelta = 0;


		GPS_lapTimer_RESET = 0;

		goto END_OF_FUNCTION;
	}

	lastPointTimeInterval = samplingTime - pointSamplingTimeOld;


	//check that the two points don't coincide
	if(latOld != lat && lonOld != lon)
	{
		//calculate the distance between the two points
		distance = GPS_DISTANCE_DEG(latOld, lonOld, lat, lon);

		if(distance < 10)		//WARNING added for problems (probably the data for spain are corrupted; should recreate the data vector)
		{
			if(distance > 0)
			{
				if(distance < minDistance || totalDistance == 0)
					minDistance = distance;

				if(distance > maxDistance || totalDistance == 0)
					maxDistance = distance;
			}

			totalDistance += distance;

			currentLapDistance = (totalDistance - lapDistanceOld);
		}
		else
		{
			//printf("\!!!!!!!!!!!!!!!!!!!!  %.10f\n", distance);
			distance = 0;
		}
	}
	else
		distance = 0;



	if(startLineStatus != 2)
	{
		if(startLineStatus == 1)
		{
			if(GPS_DISTANCE_DEG(lapStart[0], lapStart[1], lat, lon) >= 2)
			{
				GPS_createRectPoints(&startLine, lapStart[0], lapStart[1], lat, lon,  START_LINE_WIDTH, START_LINE_LENGTH, GPS_DEGREE);

				startLineStatus = 2;
			}
		}

		currentLapDistance = 0;

		goto END_OF_FUNCTION;
	}



	processedSamples++;		//take a count of processed points (samples from the GPS)


////////////////////////////////////////////////LAPS MANAGEMENT BEGIN

	//the following section detect the start-finish of the laps and parts of their data (laps' parameters and times)
	{
		int carOnStartLine = GPS_isPointInRect(&startLine, lat, lon);

		if(carOnStartLine == 1 && carOnStartLineOld == 0)					//the debounce system detect the start of a new lap
		{																	//WARNING: consider to add a timeout (the car could stand in place)

			register float direction = GPS_DIRECTION_DEG(lat, lon, latOld, lonOld);	//calculate the actual direction of the car

			direction += (180 - startLine.direction);						//add an offset to use the data in the middle of 360 (to avoid 370 = 10 ecc...)

			//check if the car is going on the same direction (direction window) of the start line (avoid fake lap start-end)
			if(180 - START_LINE_DIRECTION_WINDOW <= direction && direction <= 180 + START_LINE_DIRECTION_WINDOW)
			{
				if(lapCounter >= 0)
				{
					laps[lapCounter].time = samplingTime - lapTimeStart;						//obtain the lap time from the starting time and the end time
					laps[lapCounter].samples = (processedSamples - lapBeginSampleNumber);			//lap's samples number
					lapBeginSampleNumber = processedSamples;										//save the samples number to calculate the next lap's sample's number

					laps[lapCounter].length = totalDistance - lapDistanceOld;						//calculate the lap's length
					laps[lapCounter].number = lapCounter + 1;

					lapDistanceOld = totalDistance;
					lapTimeStart = samplingTime;												//refresh the lap time
				}
				else
				{
					lapBeginSampleNumber = processedSamples;					//erase the lapBeginSampleNumber to correctly calculate the next lap
					lapDistanceOld = totalDistance;								//erase the lapDistanceOld to correctly calculate the next lap

					lapTimeStart = samplingTime;
				}

				lapCounter++;											//increment the lapCounter (lap number) every time the car is on the starting point
			}
		}

		carOnStartLineOld = carOnStartLine;							//refresh the carOnStartLineOld used as debounce
	}

////////////////////////////////////////////////LAPS MANAGEMENT END





////////////////////////////////////////////////SECTORS DEFINITION AT DESIGNED LAP BEGIN

	//the following procedure is used on the first lap to find the sectors in a lap every SECTORS_LENGTH meters
	{
		if(lapCounter < SECTORS_CALCULATION_LAP)	//if there is no lap started keep the data erased
		{
			sectorNumber = 0;
			sectorLength = 0;
		}
		else
		{
			if(lapCounter == SECTORS_CALCULATION_LAP)	//if the first lap has started, find the coordinates of the sectors
			{
				sectorLength += distance;			//calculate the length of each sector

				sectorSamples++;						//used to calculate the travel time of the sector

				if(sectorLength >= SECTORS_LENGTH)		//if the machine has traveled the distance of the sector, the data of the sector are saved
				{
					sectors[sectorNumber].length = sectorLength;							//save the sector length in meters
					sectors[sectorNumber].lat = lat;										//save the latitude of the sector's end point in radiant
					sectors[sectorNumber].lon = lon;										//save the longitude of the sector's end point in radiant
					sectors[sectorNumber].number = sectorNumber + 1;						//save the number of the sector (like if it's a sector's ID)
					sectors[sectorNumber].lastTime = samplingTime - sectorTimeStart;
					sectors[sectorNumber].bestTime = sectors[sectorNumber].lastTime;		//set the sector's best time travel at the first time travel calculated
					sectors[sectorNumber].bestTimeLap = lapCounter;							//set the lap's fastest sector number (to detect in with lap has been set the best time)

					//printf("Sector: %d, Samples: %d\n", sectorNumber, sectorSamples);

					if(sectorNumber == 0)													//the first sector begin at the start line than the distance from the start line is 0
						sectors[sectorNumber].distance = 0;
					else
						sectors[sectorNumber].distance = sectors[sectorNumber - 1].distance + sectors[sectorNumber - 1].length;	//set the distance of the begin of the sector from the start line

					laps[lapCounter].sectorTimes[sectorNumber] = sectors[sectorNumber].lastTime;		//set the lap's sector's time
					laps[lapCounter].sectorStatus[sectorNumber] = 0;									//there are no problem in the sector
					laps[lapCounter].sectorDeltaFastestLap[sectorNumber] = 0;								//there is non delta from any other previous lap

					sectorNumber++;															//the procedure for the sector is ended than increment the pointer

					sectorRectToCalculate = 1;

					sectorSamplesSum += sectorSamples;

					sectorLength = 0;														//must be erased to calculate data for the next sector
					sectorSamples = 0;														//must be erased to calculate data for the next sector
					sectorTimeStart = samplingTime;
				}
				else if (sectorNumber == 0 && sectorSamples == 1)		//for the first sector is needed to set the sector time start
					sectorTimeStart = samplingTime;

				if(sectorRectToCalculate == 1)				//if a new sector is found is needed to calculate his rectangle
				{
					if(distance > 0)						//calculate the rectangle only there is a new point (not if the new sample has the same coordinates)
					{
						if(sectorLength > 0)				//if the sector has a distance (not a fake sector)
						{
							GPS_createRectPoints(&sectors[sectorNumber-1].rect, sectors[sectorNumber-1].lat, sectors[sectorNumber-1].lon, lat, lon,  SECTORS_RECT_WIDTH, SECTORS_RECT_LENGTH, GPS_DEGREE);

							sectorRectToCalculate = 0;		//the sector is calculated (wait an other sector)
						}
					}
				}
			}
			else if (lapCounter == SECTORS_CALCULATION_LAP + 1 && lastSectorDetected == 0)	//if the lap is completed, calculate the last sector's data
			{
				float distanceToStartLine = GPS_DISTANCE_DEG(sectors[sectorNumber - 1].lat, sectors[sectorNumber - 1].lon, lapStart[0], lapStart[1]);

				if(distanceToStartLine >= LAST_SECTOR_MIN_LENGTH)
				{
					//if there is enough space between the last rectangle and the start line provide to calculate the last sector

					sectors[sectorNumber].length = GPS_DISTANCE_DEG(sectors[sectorNumber - 1].lat, sectors[sectorNumber - 1].lon, lapStart[0], lapStart[1]);
					sectors[sectorNumber].lat = lapStart[0];									//save the latitude of the sector's end point
					sectors[sectorNumber].lon = lapStart[1];									//save the longitude of the sector's end point
					sectors[sectorNumber].number = sectorNumber + 1;							//save the number of the sector (like if it's a sector's ID)

					//printf("\n\nSector time sum: %.2f, lap time: %.2f\n\n", (sectorSamplesSum + sectorSamples)*GPS_SAMPLING_TIME/1000.0, laps[lapCounter - 1].time/1000.0);

					sectors[sectorNumber].lastTime = samplingTime - sectorTimeStart;

					sectors[sectorNumber].bestTime = sectors[sectorNumber].lastTime;			//set the sector's best time travel at the first time travel calculated
					sectors[sectorNumber].bestTimeLap = lapCounter - 1;							//set the lap's fastest sector number (to detect in which lap has been set the best time)



					if(sectorNumber == 0)														//the first sector begin at the start line than the distance from the start line is 0
						sectors[sectorNumber].distance = 0;
					else
						sectors[sectorNumber].distance = sectors[sectorNumber - 1].distance + sectors[sectorNumber - 1].length;	//set the distance of the begin of the sector from the start line

					sectorNumber++;					//add the last calculated sector at the count
				}
				else
				{
					//if the previous rectangle is too close to the finish line it's considered as the last sector

					sectors[sectorNumber - 1].length += distanceToStartLine;
					sectors[sectorNumber - 1].lat = lapStart[0];									//save the latitude of the sector's end point
					sectors[sectorNumber - 1].lon = lapStart[1];									//save the longitude of the sector's end point

					sectors[sectorNumber - 1].lastTime += (samplingTime - sectorTimeStart);

					sectors[sectorNumber - 1].bestTime = sectors[sectorNumber - 1].lastTime;		//set the sector's best time travel at the first time travel calculated
					sectors[sectorNumber - 1].bestTimeLap = lapCounter - 1;							//set the lap's fastest sector number (to detect in which lap has been set the best time)
				}

				laps[lapCounter - 1].sectorTimes[sectorNumber - 1] = sectors[sectorNumber - 1].lastTime;	//set the lap's sector's time
				laps[lapCounter - 1].sectorCounter = sectorNumber - 1;
				laps[lapCounter - 1].sectorStatus[sectorNumber - 1] = 0;									//there are no problem in the sector
				laps[lapCounter - 1].sectorDeltaFastestLap[sectorNumber - 1] = 0;							//there is non delta from any other previous lap

				lastSectorDetected = 1;		//notifies that the last sector is calculated (to not fall again under this code)
			}
		}
	}

////////////////////////////////////////////////SECTORS DEFINITION AT DESIGNED LAP END





////////////////////////////////////////////////SECTORS MANAGEMENT BEGIN

	//the following section detect the sectors' times in the current lap
	{
		if(lastSectorDetected)
		{
			if(lapCounter != lapCounterOld)
			{
				if(lapCounter > SECTORS_CALCULATION_LAP + 1)	//the last sector of the previous lap must be calculated
				{
					laps[lapCounter - 1].sectorTimes[sectorNumber - 1] = currentSectorTime;
					laps[lapCounter - 1].sectorDeltaFastestLap[sectorNumber - 1] = currentSectorTime - laps[fastestLapPointerOld].sectorTimes[currentSectorCounter];
					laps[lapCounter - 1].sectorStatus[sectorNumber - 1] = 0;
					laps[lapCounter].sectorCounter++;			//WARNING: I don't know why i have to change lapCounter instead lapCounter-1

					if(laps[lapCounter - 1].sectorTimes[sectorNumber - 1] != 0 && laps[lapCounter - 1].sectorTimes[sectorNumber - 1] < sectors[sectorNumber - 1].bestTime)
					{
						sectors[sectorNumber - 1].bestTime = laps[lapCounter - 1].sectorTimes[sectorNumber - 1];
						sectors[sectorNumber - 1].bestTimeLap = lapCounter - 1;
					}

					lapTimeDelta = liveTimeDelta + laps[lapCounter - 1].sectorDeltaFastestLap[sectorNumber - 1];

					//printf("%f\n\n", lapTimeDelta/1000.0);

					liveTimeDelta = 0;
				}

				currentSectorCounter = 0;
				currentSectorTime = 0;
			}

			register int carOnSectorPoint = 0;						//used to detect if the car is on the sector's point

			currentSectorSamples++;
			currentSectorTime += lastPointTimeInterval;

			carOnSectorPoint = GPS_isPointInRect(&sectors[currentSectorCounter].rect, lat, lon);		//check if the car is on the sector's rectangle

			if(carOnSectorPoint == 1 && carOnSectorPointOld == 0)
			{
				laps[lapCounter].sectorTimes[currentSectorCounter] = currentSectorTime;
				laps[lapCounter].sectorDeltaFastestLap[currentSectorCounter] = currentSectorTime - laps[fastestLapPointer].sectorTimes[currentSectorCounter];
				laps[lapCounter].sectorStatus[currentSectorCounter] = 0;

				currentSectorSamples = 0;
				currentSectorTime = 0;
				carOnSectorPointOld = carOnSectorPoint;

				if(laps[lapCounter].sectorTimes[currentSectorCounter] != 0 && laps[lapCounter].sectorTimes[currentSectorCounter] < sectors[currentSectorCounter].bestTime)
				{
					sectors[currentSectorCounter].bestTime = laps[lapCounter].sectorTimes[currentSectorCounter];
					sectors[currentSectorCounter].bestTimeLap = lapCounter + 1;
				}

				liveTimeDelta += laps[lapCounter].sectorDeltaFastestLap[currentSectorCounter];

				currentSectorCounter++;
				laps[lapCounter].sectorCounter = currentSectorCounter ;

				/*
				//printf("\nLap %d, Sector %d", lapCounter, currentSectorCounter);
				if(liveTimeDelta >= 0)
					printf("Lap %d, Sector %d, Live Delta: 	+%.3f\n", lapCounter + 1, laps[lapCounter].sectorCounter, liveTimeDelta/1000.0);
				else
					printf("Lap %d, Sector %d, Live Delta: 	%.3f\n", lapCounter + 1, laps[lapCounter].sectorCounter, liveTimeDelta/1000.0);
				*/

				/*
				if(liveTimeDelta >= 0)
					printf("%d, %d, +%d,\n", lapCounter + 1, laps[lapCounter].sectorCounter, liveTimeDelta);
				else
					printf("%d, %d, %d,\n", lapCounter + 1, laps[lapCounter].sectorCounter, liveTimeDelta);
				 */
			}
			else
			{
				carOnSectorPointOld = carOnSectorPoint;

				if(currentSectorCounter < sectorNumber - 1)
				{
					if(GPS_isPointInRect(&sectors[currentSectorCounter + 1].rect, lat, lon))
					{
						carOnSectorPoint = 1;

						laps[lapCounter].sectorTimes[currentSectorCounter] = 0;
						laps[lapCounter].sectorStatus[currentSectorCounter] = 1;
						laps[lapCounter].sectorDeltaFastestLap[currentSectorCounter] = -laps[fastestLapPointer].sectorTimes[currentSectorCounter];

						liveTimeDelta += laps[lapCounter].sectorDeltaFastestLap[currentSectorCounter];


						laps[lapCounter].sectorTimes[currentSectorCounter + 1] = currentSectorTime;
						laps[lapCounter].sectorStatus[currentSectorCounter + 1] = 0;
						laps[lapCounter].sectorDeltaFastestLap[currentSectorCounter + 1] = currentSectorTime - laps[fastestLapPointer].sectorTimes[currentSectorCounter + 1];

						liveTimeDelta += laps[lapCounter].sectorDeltaFastestLap[currentSectorCounter + 1];

						currentSectorCounter += 2;
						laps[lapCounter].sectorCounter = currentSectorCounter;

						currentSectorSamples = 0;
						currentSectorTime = 0;
						carOnSectorPointOld = carOnSectorPoint;
					}
					else if(currentLapDistance >= sectors[currentSectorCounter + 2].distance)
					{
						for(int h = currentSectorCounter + 2; h < sectorNumber; h++)
						{
							if(GPS_isPointInRect(&sectors[h].rect, lat, lon))
							{
								for(int p = currentSectorCounter; p < h - 1; p++)
								{
									laps[lapCounter].sectorTimes[p] = 0;
									laps[lapCounter].sectorStatus[p] = 1;
									laps[lapCounter].sectorDeltaFastestLap[p] = -laps[fastestLapPointer].sectorTimes[p];

									liveTimeDelta += laps[lapCounter].sectorDeltaFastestLap[p];
								}

								laps[lapCounter].sectorTimes[h] = currentSectorTime;
								laps[lapCounter].sectorStatus[h] = 0;

								laps[lapCounter].sectorDeltaFastestLap[h] = currentSectorTime - laps[fastestLapPointer].sectorTimes[h];

								liveTimeDelta += laps[lapCounter].sectorDeltaFastestLap[h];


								currentSectorCounter = h + 1;
								laps[lapCounter].sectorCounter = currentSectorCounter + 1;

								currentSectorSamples = 0;
								currentSectorTime = 0;
								carOnSectorPointOld = 0;

								break;
							}
						}
					}
				}
			}
		}
	}

	//printf("\nLap %d, Sector %d, Live Delta: %.3f", lapCounter, laps[lapCounter].sectorCounter, liveTimeDelta/1000.0);

////////////////////////////////////////////////SECTORS MANAGEMENT END





////////////////////////////////////////////////FASTEST LAP DETECTION MANAGEMENT BEGIN

	//if(0)
	{
		if(lapCounter == 0 || laps[lapCounter - 1].time < laps[fastestLapPointer].time)		//detect the fastest lap
		{
			if(laps[lapCounter - 1].time >= 10000)
			{
				secondFastestLapPointer = lapCounter - 1;
				fastestLapPointer = lapCounter - 1;													//refresh the fastestLapPointer with the current lap number

				for(int h = 0; h < lapCounter - 1; h++)
				{
					laps[h].delay = laps[h].time - laps[fastestLapPointer].time;							//recalculate the time delta from the best lap for each lap

					for(int k = 0; k < sectorNumber; k++)														//recalculate the sectors' time delta from the best's lap's sectors
					{
						laps[h].sectorDeltaFastestLap[k] = laps[h].sectorTimes[k] - laps[fastestLapPointer].sectorTimes[k];
						laps[fastestLapPointer].sectorDeltaFastestLap[k] = 0;
					}
				}
			}
		}
		else
		{
			laps[lapCounter - 1].delay = laps[lapCounter - 1].time - laps[fastestLapPointer].time;			//calculate the time delta from the best lap
		}
	}

////////////////////////////////////////////////FASTEST LAP DETECTION MANAGEMENT END






	if(lapCounter < -1)
		discardedSamplesFirstLap = processedSamples;	//used to calculate the samples unused before the start point of the lap


	GPS_CAR_DataCopy(dataset);

	END_OF_FUNCTION:;

	latOld = lat;
	lonOld = lon;

	pointSamplingTimeOld = samplingTime;
	lapCounterOld = lapCounter;
	fastestLapPointerOld = fastestLapPointer;

}












/**
  * @brief  Find 4 points/vertex composing a rectangle with the reference point at the center.
  *
  * @param  rect is the point where will be stored the calculated rectangle.
  * @param  latitude1 is the latitude of the reference point.
  * @param  longitude1 is the longitude of the reference point.
  * @param  direction is the direction (orientation) of the rectangle
  * @param	width is the width of the rectangle used as valid area in meters.
  * @param  length is the length of the rectangle used as valid area in meters.
  * @param  angleUnit specify if the inserted data are in degree or radiant (GPS degUnit).
  *
  *
  * @retval the results are stored in the rect param; the angle unit is the same of the inserted data (angleUnit)
  */
void GPS_createRect(gps_rect* rect, float latitude1, float longitude1, float direction, float width, float length, int angleUnit)
{
	rect->length = length;
	rect->width = width;
	rect->refPoint.latitude = latitude1;
	rect->refPoint.longitude = longitude1;
	rect->direction = direction;

	//convert all the angles in degree from radiant
	if(angleUnit == GPS_DEGREE)
	{
		latitude1 = degToRad(latitude1);
		longitude1 = degToRad(longitude1);
	}

	register float deltaDirezione;
	register float direction1P;
	register float latitudeP;
	register float longitudeP;

	//point 0
	deltaDirezione = +90;
	direction1P = direction + deltaDirezione;
	latitudeP = asin(sin(latitude1) * cos((width/2) / R) + cos(latitude1) * sin((width/2) / R) * cos(degToRad(direction1P)));
	longitudeP = longitude1 + atan2(sin(degToRad(direction1P)) * sin((width/2) / R) * cos(latitude1), cos((width/2) / R) - sin(latitude1) * sin(latitudeP));

	rect->points[0].latitude = latitudeP;
	rect->points[0].longitude = longitudeP;

	//point 1
	deltaDirezione = -90;
	direction1P = direction + deltaDirezione;
	latitudeP = asin(sin(latitude1) * cos((width/2) / R) + cos(latitude1) * sin((width/2) / R) * cos(degToRad(direction1P)));
	longitudeP = longitude1 + atan2(sin(degToRad(direction1P)) * sin((width/2) / R) * cos(latitude1), cos((width/2) / R) - sin(latitude1) * sin(latitudeP));

	rect->points[1].latitude = latitudeP;
	rect->points[1].longitude = longitudeP;

	//point 2
	deltaDirezione = -180;
	direction1P = direction + deltaDirezione;
	latitudeP = asin(sin(rect->points[1].latitude) * cos((length/2) / R) + cos(rect->points[1].latitude) * sin((length/2) / R) * cos(degToRad(direction1P)));
	longitudeP = rect->points[1].longitude + atan2(sin(degToRad(direction1P)) * sin((length/2) / R) * cos(rect->points[1].latitude), cos((length/2) / R) - sin(rect->points[1].latitude) * sin(latitudeP));

	rect->points[2].latitude = latitudeP;
	rect->points[2].longitude = longitudeP;

	//point 3
	deltaDirezione = +180;
	direction1P = direction + deltaDirezione;
	latitudeP = asin(sin(rect->points[0].latitude) * cos((length/2) / R) + cos(rect->points[0].latitude) * sin((length/2) / R) * cos(degToRad(direction1P)));
	longitudeP = rect->points[0].longitude + atan2(sin(degToRad(direction1P)) * sin((length/2) / R) * cos(rect->points[0].latitude), cos((length/2) / R) - sin(rect->points[0].latitude) * sin(latitudeP));

	rect->points[3].latitude = latitudeP;
	rect->points[3].longitude = longitudeP;

	if(angleUnit == GPS_DEGREE)
	{
		rect->points[0].latitude = radToDeg(rect->points[0].latitude);
		rect->points[0].longitude = radToDeg(rect->points[0].longitude);

		rect->points[1].latitude = radToDeg(rect->points[1].latitude);
		rect->points[1].longitude = radToDeg(rect->points[1].longitude);

		rect->points[2].latitude = radToDeg(rect->points[2].latitude);
		rect->points[2].longitude = radToDeg(rect->points[2].longitude);

		rect->points[3].latitude = radToDeg(rect->points[3].latitude);
		rect->points[3].longitude = radToDeg(rect->points[3].longitude);
	}
}


/**
  * @brief  Find 4 points/vertex composing a rectangle centered on the reference point and parallel whit the segment between two points.
  *
  * @param  rect is the point where will be stored the calculated rectangle.
  * @param  latitude1 is the latitude of the reference point.
  * @param  longitude1 is the longitude of the reference point.
  * @param  latitude2 is the latitude of the point used to find the direction.
  * @param  longitude2 is the longitude of the point to used to find the direction.
  * @param	width is the width of the rectangle used as valid area in meters.
  * @param  length is the length of the rectangle used as valid area in meters.
  * @param  angleUnit specify if the inserted data are in degree or radiant (GPS degUnit).
  *
  *
  * @retval the results are stored in the rect param; the angle unit is the same of the inserted data (angleUnit)
  */
void GPS_createRectPoints(gps_rect* rect, float latitude1, float longitude1, float latitude2, float longitude2, float width, float length, int angleUnit)
{
	rect->length = length;
	rect->width = width;
	rect->refPoint.latitude = latitude1;
	rect->refPoint.longitude = longitude1;

	//convert all the angles in degree from radiant
	if(angleUnit == GPS_DEGREE)
	{
		latitude1 = degToRad(latitude1);
		longitude1 = degToRad(longitude1);
		latitude2 = degToRad(latitude2);
		longitude2 = degToRad(longitude2);
	}

	float deltaFi = log(tan(latitude2 / 2 + pi / 4) / tan(latitude1 / 2 + pi / 4));
	float deltaLon = (longitude2 - longitude1);

	float direction12 = radToDeg(atan2(deltaLon, deltaFi));
	deltaLon < 0 ? direction12 = direction12 + 360 : 1;

	rect->direction = direction12;

	//printf("\nDistanza AB: %.2f, Direzione: %.2f\n", distance12, direction12);

	//calculated the distance12 and the direction12 is possible to calculate the 4 points/vertex composing the rectangle

	register float deltaDirezione;
	register float direction1P;
	register float latitudeP;
	register float longitudeP;

	//point 0
	deltaDirezione = +90;
	direction1P = direction12 + deltaDirezione;
	latitudeP = asin(sin(latitude1) * cos((width/2) / R) + cos(latitude1) * sin((width/2) / R) * cos(degToRad(direction1P)));
	longitudeP = longitude1 + atan2(sin(degToRad(direction1P)) * sin((width/2) / R) * cos(latitude1), cos((width/2) / R) - sin(latitude1) * sin(latitudeP));

	rect->points[0].latitude = latitudeP;
	rect->points[0].longitude = longitudeP;

	//point 1
	deltaDirezione = -90;
	direction1P = direction12 + deltaDirezione;
	latitudeP = asin(sin(latitude1) * cos((width/2) / R) + cos(latitude1) * sin((width/2) / R) * cos(degToRad(direction1P)));
	longitudeP = longitude1 + atan2(sin(degToRad(direction1P)) * sin((width/2) / R) * cos(latitude1), cos((width/2) / R) - sin(latitude1) * sin(latitudeP));

	rect->points[1].latitude = latitudeP;
	rect->points[1].longitude = longitudeP;

	//point 2
	deltaDirezione = -180;
	direction1P = direction12 + deltaDirezione;
	latitudeP = asin(sin(rect->points[1].latitude) * cos((length/2) / R) + cos(rect->points[1].latitude) * sin((length/2) / R) * cos(degToRad(direction1P)));
	longitudeP = rect->points[1].longitude + atan2(sin(degToRad(direction1P)) * sin((length/2) / R) * cos(rect->points[1].latitude), cos((length/2) / R) - sin(rect->points[1].latitude) * sin(latitudeP));

	rect->points[2].latitude = latitudeP;
	rect->points[2].longitude = longitudeP;

	//point 3
	deltaDirezione = +180;
	direction1P = direction12 + deltaDirezione;
	latitudeP = asin(sin(rect->points[0].latitude) * cos((length/2) / R) + cos(rect->points[0].latitude) * sin((length/2) / R) * cos(degToRad(direction1P)));
	longitudeP = rect->points[0].longitude + atan2(sin(degToRad(direction1P)) * sin((length/2) / R) * cos(rect->points[0].latitude), cos((length/2) / R) - sin(rect->points[0].latitude) * sin(latitudeP));

	rect->points[3].latitude = latitudeP;
	rect->points[3].longitude = longitudeP;


	if(angleUnit == GPS_DEGREE)
	{
		rect->points[0].latitude = radToDeg(rect->points[0].latitude);
		rect->points[0].longitude = radToDeg(rect->points[0].longitude);

		rect->points[1].latitude = radToDeg(rect->points[1].latitude);
		rect->points[1].longitude = radToDeg(rect->points[1].longitude);

		rect->points[2].latitude = radToDeg(rect->points[2].latitude);
		rect->points[2].longitude = radToDeg(rect->points[2].longitude);

		rect->points[3].latitude = radToDeg(rect->points[3].latitude);
		rect->points[3].longitude = radToDeg(rect->points[3].longitude);
	}
}




/**
  * @brief  Checks if the entered point is in a radius from the reference point.
  *
  * @param  latitudeRef is the latitude of the reference point.
  * @param  longitudeRef is the longitude of the reference point.
  * @param  latitude is the latitude of the point to check.
  * @param  longitude is the longitude of the point to check.
  * @param  angleUnit specify if the inserted data are in degree or radiant (GPS degUnit).
  *
  * @note   To change the radius change the value in the following define: GPS_ISINPLACE_CHECK_DISTANCE.
  *
  * @retval 1 == in place; 0 == not in place.
  */
int GPS_isInPlace(float latitudeRef, float longitudeRef, float latitude, float longitude, int angleUnit)
{
	//convert all the angles in degree from radiant
	if(angleUnit == GPS_DEGREE)
	{
		latitudeRef = degToRad(latitudeRef);
		longitudeRef = degToRad(longitudeRef);
		latitude = degToRad(latitude);
		longitude = degToRad(longitude);
	}

	register float distance = latitude - latitudeRef;		//calculate the angle distance from the two points

	if(distance < 0)										//WARNING: can be changed with ABS() function or ASM instruction (STM32 dashboard)
		distance *= -1;

	if(distance < GPS_ISINPLACE_CHECK_DISTANCE)				//if the latitude is close enough then check the longitude in the same way
	{
		distance = longitude - longitudeRef;				//calculate the angle distance from the two points

		if(distance < 0)									//WARNING: can be changed with ABS() function or ASM instruction (STM32 dashboard)
			distance *= -1;

		if(distance < GPS_ISINPLACE_CHECK_DISTANCE)		//if the longitude is close enough return GPS_IN_PLACE
			return 1;
	}

	return 0;								//if the points are not enough close return GPS_NOT_IN_PLACE
}


/**
  * @brief  Checks if the entered point is in the rectangle.
  * @param  rect is a pointer of the rectangle which contains the information about the rectangle used as area.
  * @param  lat is the latitude of the point to check.
  * @param	lon is the latitude of the point to check.
  *
  * @note	if the point is on the bound of the rectangle is considered out
  * @note	due to the float's approximation is not possible to consider "in" the points on the bound
  *
  * @retval 1 == in rectangle; 0 == not in rectangle.
  */
int GPS_isPointInRect(gps_rect *rect, float lat, float lon)
{
	/*
	 * The following code find the half plane of a line passing on two points and check if the point is on the same.
	 * If the point is on the same half plane of the line than check the next couple.
	 *
	 * To find the half plane we first calculate the line equation between two points, than we calculate the half plane.
	 */

	register unsigned int lineHalfPlane;
	register unsigned int pointHalfPlane;

	register float m;
	register float q;

	//line 01
	if(rect->points[0].latitude != rect->points[1].latitude)		//check if the line is horizontal
	{
		m = (rect->points[0].longitude - rect->points[1].longitude) / (rect->points[0].latitude - rect->points[1].latitude);
		q = (rect->points[0].latitude * rect->points[1].longitude - rect->points[1].latitude * rect->points[0].longitude) / (rect->points[0].latitude - rect->points[1].latitude);

		lineHalfPlane = (rect->points[2].longitude - (m * rect->points[2].latitude + q)) > 0 ? 1 : 0;	//where is the point 2 respect the line 01
		pointHalfPlane = (lon - (m * lat + q)) > 0 ? 1 : 0;												//where is the point   respect the line 01

		if(lineHalfPlane != pointHalfPlane)		//if the two points are not in the same half plane
			return 0;							//the point is not inside the rectangle
	}
	else
	{
		//if the line is horizontal than we have to check only the latitude of the two points
		if(!(rect->points[2].latitude > rect->points[0].latitude && lat > rect->points[0].latitude))	//if the two points are not in the same half plane
			return 0;																					//the point is not inside the rectangle
	}

	//line 12
	if(rect->points[1].latitude != rect->points[2].latitude)
	{
		m = (rect->points[1].longitude - rect->points[2].longitude) / (rect->points[1].latitude - rect->points[2].latitude);
		q = (rect->points[1].latitude * rect->points[2].longitude - rect->points[2].latitude * rect->points[1].longitude) / (rect->points[1].latitude - rect->points[2].latitude);

		lineHalfPlane = (rect->points[3].longitude - (m * rect->points[3].latitude + q)) > 0 ? 1 : 0;	//where is the point 3 respect the line 12
		pointHalfPlane = (lon - (m * lat + q)) > 0 ? 1 : 0;												//where is the point   respect the line 12

		if(lineHalfPlane != pointHalfPlane)
			return 0;
	}
	else
	{
		if(!(rect->points[3].latitude > rect->points[1].latitude && lat > rect->points[1].latitude))
			return 0;
	}

	//line 23
	if(rect->points[2].latitude != rect->points[3].latitude)
	{
		m = (rect->points[2].longitude - rect->points[3].longitude) / (rect->points[2].latitude - rect->points[3].latitude);
		q = (rect->points[2].latitude * rect->points[3].longitude - rect->points[3].latitude * rect->points[2].longitude) / (rect->points[2].latitude - rect->points[3].latitude);

		lineHalfPlane = (rect->points[0].longitude - (m * rect->points[0].latitude + q)) > 0 ? 1 : 0;	//where is the point 0 respect the line 23
		pointHalfPlane = (lon - (m * lat + q)) > 0 ? 1 : 0;												//where is the point   respect the line 23

		if(lineHalfPlane != pointHalfPlane)
			return 0;
	}
	else
	{
		if(!(rect->points[0].latitude > rect->points[2].latitude && lat > rect->points[2].latitude))
			return 0;
	}

	//line 30
	if(rect->points[3].latitude != rect->points[4].latitude)
	{
		m = (rect->points[3].longitude - rect->points[0].longitude) / (rect->points[3].latitude - rect->points[0].latitude);
		q = (rect->points[3].latitude * rect->points[0].longitude - rect->points[0].latitude * rect->points[3].longitude) / (rect->points[3].latitude - rect->points[0].latitude);

		lineHalfPlane = (rect->points[1].longitude - (m * rect->points[1].latitude + q)) > 0 ? 1 : 0;	//where is the point 1 respect the line 30
		pointHalfPlane = (lon - (m * lat + q)) > 0 ? 1 : 0;												//where is the point   respect the line 30

		if(lineHalfPlane != pointHalfPlane)
			return 0;
	}
	else
	{
		if(!(rect->points[1].latitude > rect->points[3].latitude && lat > rect->points[3].latitude))
			return 0;
	}

	return 1;		//the point is in the rectangle
}

void GPS_lapTimerReset(void)
{
	GPS_lapTimer_RESET = 1;	//reset all the static variables
}

void GPS_lapSetStarPoint(float lat, float lon)
{
	lapStart[0] = lat;		//set the latitude
	lapStart[1] = lon;		//set the longitude

	startLineStatus = 1;	//enable the starting line detection procedure
}

void GPS_CAR_DataCopy(Dataset* dataset)
{
	if(lapCounter > 0)
	{
		dataset->bestLapTime = laps[fastestLapPointer].time;
		dataset->lapTime = laps[lapCounter - 1].time;
		dataset->lapTimeDelta = liveTimeDelta;

		dataset->lapSector = sectorNumber;
	}

	dataset->lapNumber = lapCounter;

	if(startLineStatus == 1)
	{
		dataset->lapStartLat = lapStart[0];
		dataset->lapStartLon = lapStart[1];
	}
}


