#include "forkLift_EventController.h"

char buff[30] = {0, };


void forkLift_EventHandler(uint8_t state) {
	static uint32_t prevTime = 0;
	// forkLift_SetState(state);

	if (HAL_GetTick() - prevTime > 1000) {
		prevTime = HAL_GetTick();
		if (Rfid_ChkUser() == 1) {
			if (state == STOP) {
				forkLift_SetState(RUN);
				printf("Start\n");
				sprintf(buff, "Wellcome User!        ");
				LCD_WriteStringXY(0, 0, buff);
				BUZZER_ClickSound();
			} else {
				forkLift_SetState(STOP);
				stepMotor_SetState(MOTOR_STOP);
				printf("End\n");
				sprintf(buff, "ForkLift Locked!        ");
				LCD_WriteStringXY(0, 0, buff);
				sprintf(buff, "MOTOR STOP             ");
				LCD_WriteStringXY(1, 0, buff);
				BUZZER_ClickSound();
			}
		} else if (Rfid_ChkUser() == -1) {
			sprintf(buff, "Invalid User!");
			LCD_WriteStringXY(0, 0, buff);
			BUZZER_FailSound();
		} else return ;
	}
}

void stepMotor_EventHandler(uint8_t state) {

	if(Button_GetState(&hBtn_MotorStop) ||
			BT_ChkRxData(&hBt3) == MOTOR_STOP) {
		stepMotor_SetState(MOTOR_STOP);
		sprintf(buff, "Fork STOP             ");
		printf("MOTOR STOP\n");
		LCD_WriteStringXY(1, 0, buff);
	}
	if(Button_GetState(&hBtn_MotorUp) ||
			BT_ChkRxData(&hBt3) == MOTOR_UP) {
		stepMotor_SetState(MOTOR_UP);
		sprintf(buff, "Fork UP             ");
		printf("MOTOR UP\n");
		LCD_WriteStringXY(1, 0, buff);
	}
	if (Button_GetState(&hBtn_MotorDown) ||
			BT_ChkRxData(&hBt3) == MOTOR_DOWN) {
		stepMotor_SetState(MOTOR_DOWN);
		sprintf(buff, "Fork Down             ");
		printf("MOTOR DOWN\n");
		LCD_WriteStringXY(1, 0, buff);
	}
}

void stepMotor_MinMaxHandler(uint8_t state) {
	if(state == MOTOR_MAX) {
		sprintf(buff, "Height is Max!");
		LCD_WriteStringXY(1, 0, buff);

		if (Button_GetState(&hBtn_MotorDown) ||
				BT_ChkRxData(&hBt3) == MOTOR_DOWN) {
			stepMotor_SetState(MOTOR_DOWN);
			sprintf(buff, "Fork Down             ");
			printf("MOTOR DOWN\n");
			LCD_WriteStringXY(1, 0, buff);
		}
	}
	else {
		sprintf(buff, "Height is Min!");
		LCD_WriteStringXY(1, 0, buff);

		if(Button_GetState(&hBtn_MotorUp) ||
				BT_ChkRxData(&hBt3) == MOTOR_UP) {
			stepMotor_SetState(MOTOR_UP);
			sprintf(buff, "Fork UP             ");
			printf("MOTOR UP  \n");
			LCD_WriteStringXY(1, 0, buff);
		}
	}
}
