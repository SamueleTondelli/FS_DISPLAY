
#include "main.h"
#include "stm32f7xx_hal.h"

#include "math.h"
#include "stdlib.h"

#ifndef __MDM_FUNCTIONS_H
#define __MDM_FUNCTIONS_H
#define _MDM_FUNCTIONS_DEFINED
#endif



typedef uint8_t byte;

extern int32_t mcu_load;

extern char NO_STRING;

#define millis uwTick

#define TRUE 1
#define true 1
#define ON 1
#define on 1
#define BEGIN 1
#define begin 1
#define START 1
#define start 1
#define OK 1
#define ok 1
#define SHOW 1
#define show 1
#define positive 1
#define POSITIVE 1

#define FALSE 0
#define false 0
#define OFF 0
#define off 0
#define END 0
#define end 0
#define STOP 0
#define stop 0
#define KO 0
#define ko 0
#define HIDE 0
#define hide 0
#define negative 0
#define NEGATIVE 0



int32_t map_int32(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
float map_float(float x, float in_min, float in_max, float out_min, float out_max);

int32_t min_int32(int32_t x1, int32_t x2);
int32_t max_int32(int32_t x1, int32_t x2);

int32_t MDM_pow(int32_t b, int32_t e);

#ifndef MAX
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

#ifndef max
#define min(a, b)  (((a) < (b)) ? (a) : (b))
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#endif


void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char* res, int afterpoint);
int dtoa(double n, char* res, int afterpoint);
int dtoa_decimalPart(double n, char* res, int afterpoint, uint8_t pointEnable);

#define SIGN_DISABLED 0
#define SIGN_ENABLED 1
#define SIGN_INVERTED 2

int dtoa_sign(double n, char* res, int afterpoint, uint8_t signEnable);

#define bitSet(var, bit) (var |= 1 << bit)
#define bitClear(var, bit) (var &= ~(1 << bit))
#define bitToggle(var, bit)  (var ^= 1 << bit)

uint8_t bitRead(uint32_t var, uint8_t bit);


//////////////////////GPIO FUNCTIONS

#define GPIO_LOW	0
#define GPIO_HIGH 	1
#define GPIO_FALL 	2
#define GPIO_RISE 	3

typedef struct
{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;

	GPIO_PinState last;
	GPIO_PinState old;

	uint32_t millis;
	uint16_t delay;

	uint8_t state;

	GPIO_PinState liveRead;

}GPIO_EdgeTypeDef;

uint8_t GPIO_AdvancedRead(GPIO_EdgeTypeDef* GPIO_ToAnalize);



//To read the LR from C code using GCC, use the following function:

#define __ASM __asm /*!< asm keyword for GNU Compiler */
#define __INLINE inline /*!< inline keyword for GNU Compiler */
#define __STATIC_INLINE static inline

/**
\brief Get Link Register
\details Returns the current value of the Link Register (LR).
\return LR Register value
*/
__attribute__( ( always_inline ) ) __STATIC_INLINE uint32_t __get_LR(void)
{
  register uint32_t result;

  __ASM volatile ("MOV %0, LR\n" : "=r" (result) );
  return(result);
}



