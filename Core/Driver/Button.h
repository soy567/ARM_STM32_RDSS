#ifndef DRIVER_BUTTON_H_
#define DRIVER_BUTTON_H_

#include "main.h"
// #include "../System/Queue.h"

#define PUSHED		0
#define RELEASED	1
#define TRUE		1
#define FALSE		0

typedef struct {
	GPIO_TypeDef *GPIO;
	uint16_t GPIO_Pin;
	uint8_t prevState;
} BUTTON_HandleTypeDef;


extern BUTTON_HandleTypeDef hBtn_MotorStop;
extern BUTTON_HandleTypeDef hBtn_MotorUp;
extern BUTTON_HandleTypeDef hBtn_MotorDown;


void BUTTON_ISR_Process(void);
uint8_t Button_GetState(BUTTON_HandleTypeDef *hButton);

#endif /* DRIVER_BUTTON_H_ */
