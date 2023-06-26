#ifndef DATASCREEN_H
#define DATASCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "main.h"
#include "DisplayConstant.h"
#include "Data/DataStatus.h"
#include "string.h"
// END

#define DATA_SCREEN_DISPLAY_MODE_NORMAL			0
#define DATA_SCREEN_DISPLAY_MODE_RACE			1
#define DATA_SCREEN_DISPLAY_MODE_SIMULATION		2
#define DATA_SCREEN_DISPLAY_MODE_PRESENTATION	3

/*
 *	DataScreen Struct (Store data about display attributes and features)
 *	@attr screen				->	Current Screen displayed
 *	@attr positionScreenList	->	Array of Screens position
 *	@attr screenList			->	Array of Screens (Used to modify in wich way the screens are disposed)
 *	@attr fps					->	Frame per second (Number of time the display is updated per second)
 *	@attr pilotMessage			->	Message to be showed to pilot
 *	@attr isPilotMessageReady	->	Flag for Message to be showed to pilot
 */
typedef struct {
	// Current Screen Number
	uint8_t screen;
	// FPS displayed to Screen
	uint8_t fps;
	// Flag for Update Display Screen
	uint8_t updateFlag;
	// Flag for Animation (for blinking box, value changed each 1s)
	uint8_t blinkFlag;
	// Counter of frames displayed
	uint8_t frameCounter;

	uint8_t updateLapTimes;
	uint8_t invalidateCurrentAlarmFlag;
} DataScreen;
/*
* Initialize DataScreen Struct
* @param *dataScreen 	-> DataScreen Struct
*/
void initializeDataScreen(DataScreen *dataScreen);
/*
 * Get Current Screen displayed
 * @param *dataScreen 	-> DataScreen Struct
 * @return				-> Current Screen
*/
uint8_t getCurrentScreen(DataScreen *dataScreen);
/*
 * Increment current Screen displayed from the screenList
 * @param *dataScreen	-> DataScreen Struct
 */
void incrementCurrentScreen(DataScreen *dataScreen);
/*
 * Get Screen FPS
 * @param *dataScreen	-> DataScreen Struct
 * @return				-> FPS value
 */
uint8_t getFpsScreen(DataScreen *dataScreen);
/*
 * Set number of FPS
 * @param *dataScreen	-> DataScreen Struct
 * @param newFps		-> Updated FPS value
 */
void setFpsScreen(DataScreen *dataScreen, uint8_t newFps);
/*
 * Set number of FPS from Struct
 * @param *dataScreen	-> DataScreen Struct
 */
void setFpsScreenFromStruct(DataScreen* dataScreen);
/*
 * Clean variable FPS Counter
 * @param *dataScreen	-> DataScreen Struct
 */
void cleanFpsCounter(DataScreen* dataScreen);
/*
 * Reset Blink Flag Value
 * @param *dataScreen	-> DataScreen Struct
 */
void changeBlinkFlag(DataScreen* dataScreen);
/*
 * Set new Display State and handle the change of status
 * @param *dataScreen		-> DataScreen Struct
 * @param newDisplayMode	-> New Display Mode
 */

#ifdef __cplusplus
}
#endif

#endif /* DATASCREEN_H */
