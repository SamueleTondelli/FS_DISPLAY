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
	// Current Screen position in screenList
	int positionScreenList;
	// List of Screens
	uint8_t screenList[SCREEN_NUMBERS];
	// FPS displayed to Screen
	uint8_t fps;

	DataStatus displayMode;

	// Flag for phase Display Introduction Presentation
	uint8_t introductionPresentationFlag;
	// Counter of frame displayed in Initial phase Display Introduction Presentation (when turn ON)
	uint8_t counterFrameIntroductionPresentation;
	// Flag for Update Display Screen
	uint8_t updateFlag;
	// Flag for Screen Name Message Enable
	uint8_t screenNameFlag;
	// Flag for Animation (for blinking box, value changed each 1s)
	uint8_t blinkFlag;
	// Counter of frames displayed
	uint8_t frameCounter;
	// Flag for Alarm Status running
	uint8_t alarmFlag;
	// Enable/Disable Alarm Flag (Used for manual disabling Alarm Status display)
	uint8_t isAlarmFlagEnabled;
	// Flag for display Notification running
	uint8_t notificationFlag;
	// Enable/Disable Notification Flag (Used to manual disabling Notification management)
	uint8_t isNotificationFlagEnabled;
	// Flag for Simulation Mode Running
	uint8_t simulationFlag;
	// Enable/Disable manually Simulation Mode
	uint8_t isSimulationModeEnabled;
	// Enable/Disable Read Datas from file
	uint8_t simulationReadFlag;
	// Flag for Presentation Mode Running
	uint8_t presentationFlag;
	// Enable/Disable Presentation Mode
	uint8_t isPresentationModeEnabled;

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
void changeDisplayMode(DataScreen* dataScreen, uint8_t newDisplayMode);
/*
 * Check if the current Display Mode is "Normal"
 * @param *dataScreen		-> DataScreen Struct
 * @return 					-> [1 true, 0 otherwise]
 */
uint8_t isDisplayModeNormal(DataScreen* dataScreen);
/*
 * Check if the current Display Mode is "Race"
 * @param *dataScreen		-> DataScreen Struct
 * @return 					-> [1 true, 0 otherwise]
 */
uint8_t isDiplayModeRace(DataScreen* dataScreen);
/*
 * Check if the current Display Mode is "Simulation"
 * @param *dataScreen		-> DataScreen Struct
 * @return 					-> [1 true, 0 otherwise]
 */
uint8_t isDisplayModeSimulation(DataScreen* dataScreen);
/*
 * Check if the current Display Mode is "Presentation"
 * @param *dataScreen		-> DataScreen Struct
 * @return 					-> [1 true, 0 otherwise]
 */
uint8_t isDisplayModePresentation(DataScreen* dataScreen);

#ifdef __cplusplus
}
#endif

#endif /* DATASCREEN_H */
