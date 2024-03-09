#include "Button.h"

void initializeButton(Button* btn, 	GPIO_TypeDef* port, uint16_t pin)
{
	btn->port = port;
	btn->pin = pin;
	btn->state = BUTTON_NOTPRESSED;
	btn->timeWhenPressed = 0;
}

GPIO_PinState readButton(Button* btn)
{
	return HAL_GPIO_ReadPin(btn->port, btn->pin);
}

ButtonState readButtonState(Button* btn)
{
	return readButton(btn) ? BUTTON_PRESSED : BUTTON_NOTPRESSED;
}

uint8_t updateButton(Button* btn)
{
	ButtonState rstate = readButtonState(btn);
	if (rstate != btn->state)
	{
		btn->state = rstate;
		if (rstate == BUTTON_PRESSED)
		{
			btn->timeWhenPressed = uwTick;
		}
		return 1;
	}
	return 0;
}
