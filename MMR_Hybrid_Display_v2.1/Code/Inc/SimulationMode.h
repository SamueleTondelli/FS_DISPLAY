#ifndef INC_SIMULATIONMODE_H_
#define INC_SIMULATIONMODE_H_

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data/Dataset.h"
#include "TimersList.h"
#include "main.h"
// END

#define SIMULATION_MODE_FILE_NAME 		"SimulationModeData.txt"
#define SIMULTATION_MODE_ROW_TEMPLATE 	"RPM,TwaterC,SOC"
#define SIMULATION_MODE_DATA_SEPARATOR	','
#define SIMULATION_MODE_COLUMNS			3
// TODO Simulation Mode nel file (.txt) non ammette spazi tra i valori. ATTENZIONE!

/*
 * Start Simulation Mode
 * @param *dataset 		-> DataSet Struct
 * @param *dataScreen 	-> DataScreen Struct
 * @param *timers	 	-> Timers Struct
 */
void startSimulationMode(Dataset* dataset, DataScreen* dataScreen, TimersList* timers);
/*
 * Stop Simulation Mode
 * @param *dataset 	-> DataSet Struct
 * @param *timers 	-> Timers Struct
 * @param error 	-> Error returned from SDCardHandler
 */
void stopSimulationMode(Dataset* dataset, TimersList* timers, int error);

#ifdef __cplusplus
}
#endif

#endif /* INC_SIMULATIONMODE_H_ */
