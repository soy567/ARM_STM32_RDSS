#include "Queue.h"


QUEUE_HandleTypeDef hQue_Btn = {0, 0, {0, }};
QUEUE_HandleTypeDef hQue_uart2 = {0, 0, {0, }};
QUEUE_HandleTypeDef hQue_uart3 = {0, 0, {0, }};


uint8_t QisEmpty(QUEUE_HandleTypeDef *hQue) {
	if(hQue->front == hQue->end) return TRUE;
	else return FALSE;
}

uint8_t QisFull(QUEUE_HandleTypeDef *hQue) {
	if(hQue->front == ((hQue->end + 1) % QBuffLen))
		return TRUE;
	else return FALSE;
}

void enQueue(QUEUE_HandleTypeDef *hQue, uint8_t data) {
	if(!QisFull(hQue)) {
		hQue->end = ((hQue->end) + 1) % QBuffLen;
		hQue->qBuffer[hQue->end] = data;
	} else return ;
}

uint8_t deQueue(QUEUE_HandleTypeDef *hQue) {
	if(!QisEmpty(hQue)) {
		hQue->front = (hQue->front + 1) % QBuffLen;
		return hQue->qBuffer[hQue->front];
	} else return -1;
}
