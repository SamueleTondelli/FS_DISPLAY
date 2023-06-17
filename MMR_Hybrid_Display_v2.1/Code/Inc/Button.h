#ifndef BUTTON_H
#define BUTTON_H

#include "main.h"

#define DEBOUNCE_TIME 100
#define GPS_SET_TIME 4000

typedef enum {
	BUTTON_PRESSED,
	BUTTON_NOTPRESSED,
	BUTTON_DISABLED
} ButtonState;

typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
	ButtonState state;
	uint32_t timeWhenPressed;
} Button;

void initializeButton(Button* btn, 	GPIO_TypeDef* port, uint16_t pin);
GPIO_PinState readButton(Button* btn);
ButtonState readButtonState(Button* btn);
uint8_t updateButton(Button* btn);

#endif
