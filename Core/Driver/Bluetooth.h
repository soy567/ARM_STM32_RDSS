#ifndef DRIVER_BLUETOOTH_H_
#define DRIVER_BLUETOOTH_H_

#include "main.h"
#include "../Controller/forkLift_Controller.h"
#include <string.h>

#define TRUE	1
#define FALSE	0


typedef struct {
	uint8_t uartRxData;
	uint8_t uartRxFlag;
	uint8_t uartRxTail;
	uint8_t eof;
	uint8_t uartRxBuff[50];
} BT_HandleTypeDef;


extern BT_HandleTypeDef hBt2;
extern BT_HandleTypeDef hBt3;


void BT_ProcRxData(BT_HandleTypeDef *hBlu, UART_HandleTypeDef *huart);
uint8_t BT_GetStrData(BT_HandleTypeDef *hBlu, uint8_t *buff);
uint8_t BT_ChkRxData(BT_HandleTypeDef *hBlu);


#endif /* DRIVER_BLUETOOTH_H_ */
