#include "Button.h"


BUTTON_HandleTypeDef hBtn_MotorStop = {GPIOB, GPIO_PIN_3, RELEASED};
BUTTON_HandleTypeDef hBtn_MotorUp = {GPIOB, GPIO_PIN_4, RELEASED};
BUTTON_HandleTypeDef hBtn_MotorDown = {GPIOB, GPIO_PIN_5, RELEASED};


/*void BUTTON_ISR_Process(void) {
	static uint8_t prevTime = 0;
	if (HAL_GetTick() - prevTime > 50) {
		prevTime = HAL_GetTick();
		if (Button_GetState(&hButton_RunStop)) {
			EnQueue(&hQue_ButtonRunStop, PUSHED);
		} else if (Button_GetState(&hButton_Dir)) {
			EnQueue(&hQue_ButtonDir, PUSHED);
		} else if (Button_GetState(&hButton_Speed)) {
			EnQueue(&hQue_ButtonSpeed, PUSHED);
		}
	}
}*/

uint8_t Button_GetState(BUTTON_HandleTypeDef *hButton) {
	uint8_t curState = HAL_GPIO_ReadPin(hButton->GPIO, hButton->GPIO_Pin);

	if ((curState == PUSHED) && (hButton->prevState != PUSHED)) {
		// HAL_Delay(10);
		hButton->prevState = PUSHED;
		return FALSE;
	}
	else if ((curState != PUSHED) && (hButton->prevState == PUSHED)) {
		// HAL_Delay(10);
		hButton->prevState = RELEASED;
		return TRUE;
	}
	return FALSE;
}
