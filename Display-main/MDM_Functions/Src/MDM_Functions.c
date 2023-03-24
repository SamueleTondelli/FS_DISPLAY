
#include "stm32f7xx_hal.h"

#include <math.h>

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#ifndef _STRING_H_
#include <string.h>
#endif


char NO_STRING = '\0';
int32_t mcu_load = 0;


int32_t map_int32(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int32_t min_int32(int32_t x1, int32_t x2)
{
	if(x1 < x2) return x1;
	else return x2;
}

int32_t max_int32(int32_t x1, int32_t x2)
{
	if(x1 > x2) return x1;
	else return x2;
}

float map_float(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int32_t MDM_pow(int32_t b, int32_t e)
{
	if (e == 0)
		return 1;
	else if (b == 0)
		return 0;
	else
	{
		int32_t p = b;

		for(int32_t i = 1; i < e; i++)
			p *= b;

		return p;
	}
}

///////////////bit operations

uint8_t bitRead(uint32_t var, uint8_t bit)
{
	uint8_t bitValue = (var >> bit) & 1;
	return bitValue;
}


// Reverses a string 'str' of length 'len'
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
	int i = 0;

	if(x == 0 && d == 0)
		str[i++] = '0';
	else
	{
		while (x)
		{
			str[i++] = (x % 10) + '0';
			x = x / 10;
		}

		// If number of digits required is more, then
		// add 0s at the beginning
		while (i < d)
			str[i++] = '0';
	}

	reverse(str, i);
	str[i] = '\0';

    return i;
}

// Converts a floating-point number to a string.
void ftoa(float n, char* res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

// Converts a double number to a string.
int dtoa(double n, char* res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    double fpart = n - (double)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    int sizeOfString = i;

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        sizeOfString += intToStr((int)fpart, res + i + 1, afterpoint);
    }

    return sizeOfString;
}


// Converts a decimal part of a double number to a string.
int dtoa_decimalPart(double n, char* res, int afterpoint, uint8_t pointEnable)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    double fpart = n - (double)ipart;

    fpart = fpart * pow(10, afterpoint);

    int sizeOfString = 0;

    if(pointEnable)
    {
    	res[0] = '.';
    	sizeOfString += intToStr((int)fpart, res + 1, afterpoint);
    }
    else
    	sizeOfString += intToStr((int)fpart, res, afterpoint);

    return sizeOfString;
}


// Converts a double number to a string with or without sign.
int dtoa_sign(double n, char* ret, int afterpoint, uint8_t signEnable)
{
	uint8_t sign = 0;

	// Calculate sign of n
	if(signEnable != SIGN_DISABLED || n == 0)
	{
		if (n > 0)
			sign = 1;
		else
			sign = 2;
	}

	// Turn n to positive if negative
	if(n < 0)
		n *= -1;

    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    double fpart = n - (double)ipart;

    if(fpart < 0) fpart = 0;

    char res[51];

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    int sizeOfString = i;

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        sizeOfString += intToStr((int)fpart, res + i + 1, afterpoint);
    }

    if(sign != 0 && n != 0)
    {
    	char c = ' ';

    	if(sign == 1)
    	{
    		if(signEnable == SIGN_ENABLED)
    			c = '+';
    		else
    			c = '-';
    	}
    	else
    	{
    		if(signEnable == SIGN_ENABLED)
				c = '-';
			else
				c = '+';
    	}

    	ret[0] = c;
    	strcpy(ret+1, res);

    	sizeOfString++;
    }
    else
    	strcpy(ret, res);


    return sizeOfString;
}


//////////////////////GPIO FUNCTIONS

uint8_t GPIO_AdvancedRead_old(GPIO_EdgeTypeDef* GPIO_ToAnalize)
{
	GPIO_ToAnalize->liveRead = HAL_GPIO_ReadPin(GPIO_ToAnalize->GPIOx, GPIO_ToAnalize->GPIO_Pin);

	if(millis >= GPIO_ToAnalize->millis + GPIO_ToAnalize->delay)
	{
		GPIO_ToAnalize->last = HAL_GPIO_ReadPin(GPIO_ToAnalize->GPIOx, GPIO_ToAnalize->GPIO_Pin);

		if(GPIO_ToAnalize->old == 0 && GPIO_ToAnalize->last == 1)
			GPIO_ToAnalize->state = GPIO_RISE;

		else if(GPIO_ToAnalize->old == 1 && GPIO_ToAnalize->last == 0)
			GPIO_ToAnalize->state = GPIO_FALL;

		else if(GPIO_ToAnalize->old == 1 && GPIO_ToAnalize->last == 1)
			GPIO_ToAnalize->state = GPIO_HIGH;

		else if(GPIO_ToAnalize->old == 0 && GPIO_ToAnalize->last == 0)
			GPIO_ToAnalize->state = GPIO_LOW;

		GPIO_ToAnalize->old = GPIO_ToAnalize->last;
		GPIO_ToAnalize->millis = millis;
	}

	return GPIO_ToAnalize->state;
}


uint8_t GPIO_AdvancedRead(GPIO_EdgeTypeDef* GPIO_ToAnalize)
{
	GPIO_ToAnalize->liveRead = HAL_GPIO_ReadPin(GPIO_ToAnalize->GPIOx, GPIO_ToAnalize->GPIO_Pin);

	if(millis >= GPIO_ToAnalize->millis + GPIO_ToAnalize->delay)
	{
		GPIO_ToAnalize->last = HAL_GPIO_ReadPin(GPIO_ToAnalize->GPIOx, GPIO_ToAnalize->GPIO_Pin);

		if(GPIO_ToAnalize->old == 0 && GPIO_ToAnalize->last == 1)
			GPIO_ToAnalize->state = GPIO_RISE;

		else if(GPIO_ToAnalize->old == 1 && GPIO_ToAnalize->last == 0)
			GPIO_ToAnalize->state = GPIO_FALL;

		else if(GPIO_ToAnalize->old == 1 && GPIO_ToAnalize->last == 1)
			GPIO_ToAnalize->state = GPIO_HIGH;

		else if(GPIO_ToAnalize->old == 0 && GPIO_ToAnalize->last == 0)
			GPIO_ToAnalize->state = GPIO_LOW;

		GPIO_ToAnalize->old = GPIO_ToAnalize->last;
		GPIO_ToAnalize->millis = millis;
	}

	return GPIO_ToAnalize->state;
}
