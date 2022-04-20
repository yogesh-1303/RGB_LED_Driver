#include "main.hpp"

/*
*objects created of rgb_led class each for one led
*/
rgb_led myobj1,myobj2;

/*
*@brief main function
*@param None
*@retval None
*/
int main()
{
	/*rgb_led class objects for both the leds*/
	rgb_led led1, led2;
	
	/*initialize pin structure for all the pins in both LEDs*/
	LL_GPIO_InitTypeDef GPIO1R_InitStruct;
	LL_GPIO_InitTypeDef GPIO1G_InitStruct;
	LL_GPIO_InitTypeDef GPIO1B_InitStruct;

	LL_GPIO_InitTypeDef GPIO2R_InitStruct;
	LL_GPIO_InitTypeDef GPIO2G_InitStruct;
	LL_GPIO_InitTypeDef GPIO2B_InitStruct;
	
	/*connect pins to the rgb_led class and initialize the LEDs*/
	led1.red_pinmask = LED1_PinR;
	led1.green_pinmask = LED1_PinG;
	led1.blue_pinmask = LED1_PinB;
	led1.led_init(LED1_GPIO_Port, GPIO1R_InitStruct, GPIO1G_InitStruct, GPIO1B_InitStruct);
	
	led2.red_pinmask = LED2_PinR;
	led2.green_pinmask = LED2_PinG;
	led2.blue_pinmask = LED2_PinB;
	led2.led_init(LED2_GPIO_Port, GPIO2R_InitStruct, GPIO2G_InitStruct, GPIO2B_InitStruct);
	
	/*set or change the state of the LEDs*/
    led1.led_state(LED1_GPIO_Port, LED1_PinR);
	led2.led_state(LED2_GPIO_Port, LED2_PinG);
    return 0;
}