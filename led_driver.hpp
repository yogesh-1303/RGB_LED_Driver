#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stm32g4xx_ll_gpio.h"

/*
*@brief contains functions to initialize the LEDs and change state
*/
class rgb_led{
    public:
        uint32_t red_pinmask, green_pinmask, blue_pinmask;
		GPIO_TypeDef *GPIOx;

		/*
		@brief initializes the LED
		*@param GPIOx GPIO Port
		*@param LL_GPIO_InitTypeDef for pin1
		*@param LL_GPIO_InitTypeDef for pin2
		*@param LL_GPIO_InitTypeDef for pin3
		*@retval None
		*/
        void led_init(GPIO_TypeDef *, LL_GPIO_InitTypeDef *, LL_GPIO_InitTypeDef *, LL_GPIO_InitTypeDef *);
		
		/*
		*@brief changes the state of the LED
		*@param GPIOx GPIO Port
		*@param uint32_t pinmask
		*@retval None
		*/
        void led_state(GPIO_TypeDef *GPIOx, uint32_t pinMask);
};

#endif