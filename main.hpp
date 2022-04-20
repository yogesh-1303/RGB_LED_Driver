#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include "led_driver.hpp"

using namespace std;

/*
*@brief macros for ports and pins used for the two leds(R=red, B=blue, G=green)
*/

#define LED1_GPIO_Port 	GPIOA
#define LED1_PinR 		LL_GPIO_PIN_0
#define LED1_PinG 		LL_GPIO_PIN_1
#define LED1_PinB 		LL_GPIO_PIN_2
#define LED1_GND 		LL_GPIO_PIN_3
#define LED2_GPIO_Port 	GPIOA
#define LED2_PinR 		LL_GPIO_PIN_5
#define LED2_PinG 		LL_GPIO_PIN_6
#define LED2_PinB 		LL_GPIO_PIN_7
#define LED2_GND  		LL_GPIO_PIN_8

#endif