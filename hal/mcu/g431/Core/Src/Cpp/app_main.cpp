#include "app_main.h"
#include <stdint.h>

#include "main.h"

#include "stm32g4xx_hal.h"

int app_main()
{
	uint32_t i = 0;
	while(1)
	{
		
		//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		

		
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		for(i = 0; i < 0xFFFFF; i++);

		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		for(i = 0; i < 0xFFFFF; i++);
	
	
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		for(i = 0; i < 0xFFFFFF; i++);

		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		for(i = 0; i < 0xFFFFFF; i++);
		
	}
}
