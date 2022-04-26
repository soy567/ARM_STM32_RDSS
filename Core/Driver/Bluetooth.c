#include "Bluetooth.h"


BT_HandleTypeDef hBt2 ={0, 0, 0, 0x0a, {0, }};
BT_HandleTypeDef hBt3 ={0, 0, 0, ';',{0, }};


void BT_ProcRxData(BT_HandleTypeDef *hBlu, UART_HandleTypeDef *huart) {
	if(hBlu->uartRxData == hBlu->eof) {
		hBlu->uartRxBuff[hBlu->uartRxTail] = hBlu->uartRxData;
		// hBlu->uartRxTail++;
		hBlu->uartRxBuff[hBlu->uartRxTail] = '\0';
		hBlu->uartRxTail = 0;
		hBlu->uartRxFlag = 1;
	} else {
		hBlu->uartRxBuff[hBlu->uartRxTail] = hBlu->uartRxData;
		hBlu->uartRxTail++;
	}
	HAL_UART_Receive_IT(huart, &hBlu->uartRxData, 1);
}

uint8_t BT_GetStrData(BT_HandleTypeDef *hBlu, uint8_t *buff) {
	if(hBlu->uartRxFlag) {
		hBlu->uartRxFlag = 0;
		strcpy(buff, hBlu->uartRxBuff);
		return TRUE;
	} else return FALSE;
}

uint8_t BT_ChkRxData(BT_HandleTypeDef *hBlu) {
	uint8_t buff[50];
	BT_GetStrData(hBlu, buff);

	if (!strncmp(buff, "MOTOR_STOP", 10))
		return MOTOR_STOP;
	else if(!strncmp(buff, "MOTOR_UP", 10))
		return MOTOR_UP;
	else if(!strncmp(buff, "MOTOR_DOWN", 10))
		return MOTOR_DOWN;
	else return -1;
}
