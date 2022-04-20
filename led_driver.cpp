
#include "led_driver.hpp"

using namespace std;

/*
@brief initializes the LED
*@param GPIOx GPIO Port
*@param LL_GPIO_InitTypeDef for pin1
*@param LL_GPIO_InitTypeDef for pin2
*@param LL_GPIO_InitTypeDef for pin3
*@retval None
*/
void rgb_led::led_init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIOR_InitStruct*, LL_GPIO_InitTypeDef *GPIOG_InitStruct*, LL_GPIO_InitTypeDef *GPIOB_InitStruct*){
	
	GPIOR_InitStruct = {0};
	GPIOB_InitStruct = {0};
	GPIOG_InitStruct = {0};

	/*set all the pins to low*/
	LL_GPIO_ResetOutputPin(GPIOx, red_pinmask);
	LL_GPIO_ResetOutputPin(GPIOx, green_pinmask);
	LL_GPIO_ResetOutputPin(GPIOx, blue_pinmask);
	
	/*initialize red, green, and blue pins' structure on by one*/
	GPIOR_InitStruct.Pin = red_pinmask;
	GPIOR_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIOR_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIOR_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIOR_InitStruct.Pull = LL_GPIO_PULL_NO;

	GPIOG_InitStruct.Pin = green_pinmask;
	GPIOG_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIOG_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIOG_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIOG_InitStruct.Pull = LL_GPIO_PULL_NO;

	GPIOB_InitStruct.Pin = blue_pinmask;
	GPIOB_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIOB_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIOB_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIOB_InitStruct.Pull = LL_GPIO_PULL_NO;
	
	/*initialize each pin*/
	LL_GPIO_Init(GPIOx, GPIOR_InitStruct);
	LL_GPIO_Init(GPIOx, GPIOG_InitStruct);
	LL_GPIO_Init(GPIOx, GPIOB_InitStruct);
}

/*
*@brief changes the state of the LED
*@param GPIOx GPIO Port
*@param uint32_t pinmask
*@retval None
*/
void rgb_led::led_state(GPIO_TypeDef *GPIOx, uint32_t pin_mask){
	if(pin_mask == red_pinmask){
		/*if state is red*/
		LL_GPIO_ResetOutputPin(GPIOx, green_pinmask);
		LL_GPIO_ResetOutputPin(GPIOx, blue_pinmask);
		LL_GPIO_SetOutputPin(GPIOx, red_pinmask);
	}
	else if(pinMask == green){
		/*if state is green*/
		LL_GPIO_ResetOutputPin(GPIOx, red_pinmask);
		LL_GPIO_ResetOutputPin(GPIOx, blue_pinmask);
		LL_GPIO_SetOutputPin(GPIOx, green_pinmask);		
	}
	else if(pinMask == blue){
		/*if state is blue*/
		LL_GPIO_ResetOutputPin(GPIOx, red_pinmask);
		LL_GPIO_ResetOutputPin(GPIOx, green_pinmask);
		LL_GPIO_SetOutputPin(GPIOx, blue_pinmask);		
	}
	else{
		/*if state is off*/
		LL_GPIO_ResetOutputPin(GPIOx, green_pinmask);
		LL_GPIO_ResetOutputPin(GPIOx, blue_pinmask);
		LL_GPIO_ResetOutputPin(GPIOx, red_pinmask);		
	}
}
