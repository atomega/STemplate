#include "main.h"
#include "app_main.h"
int app_main()
{
	HAL_GPIO_WritePin(GPIOA, ENABLE_Pin|MUTE_Pin|POWER_Pin, GPIO_PIN_SET);
	HAL_Delay(300);
	HAL_GPIO_WritePin(GPIOA, ENABLE_Pin|MUTE_Pin|POWER_Pin, GPIO_PIN_RESET);
	HAL_Delay(300);
	return 1; 
}
