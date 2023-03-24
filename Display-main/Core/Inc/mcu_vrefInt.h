/*
 * This is the header file of "mcu_vbat.c" where there are some functions
 * to read the MCU's internal temperature sensor
 *
 * To use these functions ADC1 must be configured correctly
 *
 * Created By Mario Di Marino (MDM)
 *
 * 21/06/2021 dd/mm/yy
 *
 */


#define __MCU_VREFINT_H

#ifndef __MAIN_H
#include "main.h"
#endif

#define MCU_VREFINT_REFRESH_TIME	500	//time in milliseconds

extern int32_t MCU_vrefInt;
extern float MCU_VrefInt;

void readMcuVrefInt(void);
