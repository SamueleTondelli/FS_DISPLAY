// START
#include "Data/Dataset.h"
#include "SDcardHandler.h"
#include "SimulationMode.h"
#include "string.h"
// FILE
#include "stdio.h" 
#include "stdlib.h"

// END

int testSDcard() {
/*
	FRESULT res;	//FatFs function common result code
	uint32_t bytesWritten, bytesRead; // File write/read counts
	uint8_t wText[] = "STM32 FATFS works great!"; // File write buffer
	uint8_t rText[_MAX_SS]; // File read buffer

	// Dopo MX_FATDS_Init();

	// Mount the SD Card
	if((res = f_mount(&SDFatFS, (TCHAR const*)SDPath, 0)) != FR_OK) {
		return -1;
	} else {
		// Format the SD Card
		if(f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, rText, sizeof(rText)) != FR_OK) {
			return -2;
		} else {
			// Open file for writing (Create)
			if(f_open(&SDFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK) {
				return -3;
			} else {
				// Write text to the text file
				res = f_write(&SDFile, wText, strlen((char*)wText), (void*)&bytesWritten);
				memset(rText, 0, sizeof(rText));
				res = f_read(&SDFile, rText, sizeof(rText), (UINT*)&bytesRead);
				if((bytesRead == 0) || (res != FR_OK)) {
					return -4;
				} else {
					return -5;
				}
				f_close(&SDFile);
			}
		}
	}
	 f_mount(&SDFatFS, (TCHAR const*)NULL, 0);
*/
	 return 0;
}

int initializeSDCard() {
	/*
	// Mount the SD Card
	FRESULT result;
	if((result = f_mount(&SDFatFS, (TCHAR const*)SDPath, 0)) != FR_OK) {
		return result;
	}
	*/
	return 0;
}

/*
int openFile(const char *fileName, const char *rowTemplate) {
	
	FRESULT result;
	FILINFO fno;
	DIR dir;

	if(fileName == NULL || rowTemplate == NULL)
			return -2;

	//result = f_stat("SimulationMode", &fno);
	//if(result == FR_OK) {
		//f_opendir(&dir, fileName);
		//result = f_stat(fileName, &fno);
		//if(result == FR_OK) {
			if(f_open(&SDFile, fileName, FA_READ) == FR_OK) {
				char readData[256] = {0}; // File read buffer
				// Read the first file row and check if is equal to Data Template readed by Display
				if(f_gets((TCHAR*)readData, sizeof(readData)/sizeof(readData[0]), &SDFile) != 0) {
					uint8_t readDataLength = strlen(readData) - 1;
					uint8_t rowTemplateLength = strlen(rowTemplate);
					if(readDataLength == rowTemplateLength) {
						int res = strncmp(readData, rowTemplate, rowTemplateLength);
						if(res != 0)
							return -3;
						else
							return 0;
					} else {
						return -4;
					}
				} else {
					return -5;
				}
			}
			return -6;	// Error open File
		} else if(result == FR_NO_FILE) {
			return -5; // No Simulation Mode Data File Found
		} else {
			return -6; // Simulation Mode Data File Other Error
		}
	} else if(result == FR_INVALID_NAME) {
		return -7; // The given string is invalid as the path name
	} else if(result == FR_DENIED) {
		return -8; // The required access was denied
	} else if(result == FR_INVALID_OBJECT) {
		return -9; // The file/directory object is invalid or a null pointer is given.
	} else {
		return -10; // Other Directory errors
	}
	return 0;
}
*/
/*
int readFileRow(Dataset *ds) {
	char readData[256]; // File read buffer
	char *resultRead;
	uint8_t flag = 0;
	int error = 0;
	do {	// TODO Aggiungere valore di ritorno di errore e esce dalla SimulationMode
		if((resultRead = f_gets(readData, (sizeof(readData)/sizeof(readData[0])), &SDFile)) == NULL) {
			if(strlen(readData) <= 1 && f_eof(&SDFile) != 0) {
				f_lseek(&SDFile, strlen(SIMULTATION_MODE_ROW_TEMPLATE)*sizeof(char)+2);
				flag = 1;
			} else {
				flag = 0;
			}
		} else {
			if(strlen(readData) <= 1) {
				flag = 1;
			} else {
				flag = 0;
			}
		}
	} while(flag != 0);
	uint16_t buffLenght = strlen(readData);
	decodifyFileRow(ds, readData, buffLenght);
	return error;
}
*/

int openFile(DataSDcard* sdCard, const char* fileName, const char* rowTemplate) {

	sdCard->file = fopen(fileName, "r");

	if (sdCard->file == NULL) {
		return -1;
	}

	// Check Header Row
	char readData[256] = { 0 }; // File read buffer
	// Read the first file row and check if is equal to Data Template readed by Display
	if(fscanf(sdCard->file, "%s", readData) > 0) {	
		uint8_t readDataLength = strlen(readData);
		uint8_t rowTemplateLength = strlen(rowTemplate);
		if (readDataLength == rowTemplateLength) {
			int res = strncmp(readData, rowTemplate, rowTemplateLength);
			if (res != 0)
				return -2;
			else
				return 0;
		} else {
			return -3;
		}
	} else {
		return -4;
	}

	return 0;
}

int createFile(DataSDcard* sdCard, const char* fileName) {
	//int num = 0;

	FILE* fptr;
	fptr = fopen(fileName, "w");

	if (fptr == NULL)
	{
		printf("Error!");
		return -1;
	}

	if (fptr != 0)
		fprintf(fptr, "%s", SIMULTATION_MODE_ROW_TEMPLATE);
	fclose(fptr);

	return 0;
}

int readFileRow(DataSDcard* sdCard, Dataset* ds) {

	if (sdCard->file == NULL) {
		return -5;
	}

	// File read buffer
	char readData[256] = {0};
	//char* resultRead;
	uint8_t flag = 0;
	//int error = 0;
	do {
		if ((/*resultRead = */fscanf(sdCard->file, "%s", readData)) > 0) {
			if (strlen(readData) <= 1 || feof(sdCard->file) == 1) {
				uint8_t startPosition = strlen(SIMULTATION_MODE_ROW_TEMPLATE) * sizeof(char);	
				fseek(sdCard->file, startPosition, SEEK_SET);
				flag = 1;
			} else {
				flag = 0;
			}
		} else {
			return -6;
		}
		// DEBUG
		//printf("DEBUG readFileRow: %s\n", readData);
	} while (flag != 0);

	if (flag == 0) {
		return decodifyFileRow(ds, readData);
	}

	return 0;
}

int decodifyFileRow(Dataset* ds, char* data) {
	char separator = SIMULATION_MODE_DATA_SEPARATOR;
	float newValue = 0;
	int position = 0;
	uint16_t dataCounter = 0;
	uint16_t dataLenght = strlen(data);
	for(size_t i = 0; i < dataLenght+1; i++) {
		if(data[i] == separator || i == (dataLenght)) {
			char value[10] = {0};
			memcpy(value, &data[position], (i-position));
			newValue = atof(value);
			insertRowDataToDataset(ds, newValue, dataCounter++);

			// DEBUG
			//printf("DEBUG decodifyFileRow: value: %s newValue: %f position: %d, i: %d\n", value, newValue, position, i);

			position = i + 1;
		}
		// DEBUG
		//printf("DEBUG For: i: %d, data[i]: %c\n", i, data[i]);
	}
	if (dataCounter != SIMULATION_MODE_COLUMNS)
		return -7;
	return 0;
}

void insertRowDataToDataset(Dataset* ds, float newValue, uint16_t dataCounter) {
	switch(dataCounter) {
		case(0):
			setValueDataNoConversion(&(ds->powerUnit.rpm), newValue);
			break;
		case(1):
			setValueDataNoConversion(&(ds->powerUnit.coolantTemperatureCV), newValue);
			break;
		case(2):
			setValueDataNoConversion(&(ds->hvElectronicsBMS.soc), newValue);
			break;
	}
}

void closeFile(DataSDcard* sdCard) {
	fclose(sdCard->file);
}
