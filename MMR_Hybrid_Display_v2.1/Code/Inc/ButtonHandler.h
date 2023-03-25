#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data/Dataset.h"
#include "main.h"
// END

/*
 * Handle all the actions related to the buttons
 * @param *dataset	-> Dataset Struct
 * @param  GPIO_Pin	-> Button identifier
 */
void buttonsActionHandler(Dataset* dataset, uint16_t GPIO_Pin);
/*
 * Manage the procedure to change the screen to the next page
 * @param *dataset	-> Dataset Struct
 */
void changeScreenButton(Dataset* dataset);
/*
 * "Clear Button" using this driver can manually disable notifications and/or Alarms
 * @param *dataset  -> Dataset Struct
 */
void clearButton(Dataset* dataset);

#ifdef __cplusplus
}
#endif

#endif	/* BUTTONHANDLER_H */
