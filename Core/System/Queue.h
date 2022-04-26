#ifndef SYSTEM_QUEUE_H_
#define SYSTEM_QUEUE_H_

#include "main.h"

#define QBuffLen	50
#define TRUE		1
#define FALSE		0

typedef struct {
	uint8_t front;
	uint8_t end;
	uint8_t qBuffer[QBuffLen];
} QUEUE_HandleTypeDef;

extern QUEUE_HandleTypeDef hQue_Btn;
extern QUEUE_HandleTypeDef hQue_uart2;
extern QUEUE_HandleTypeDef hQue_uart3;


uint8_t QisEmpty(QUEUE_HandleTypeDef *hQue);
uint8_t QisFull(QUEUE_HandleTypeDef *hQue);
void enQueue(QUEUE_HandleTypeDef *hQue, uint8_t data);
uint8_t deQueue(QUEUE_HandleTypeDef *hQue);


#endif /* SYSTEM_QUEUE_H_ */
