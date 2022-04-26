#ifndef DRIVER_BUZZER_H_
#define DRIVER_BUZZER_H_

#include "main.h"


void BUZZER_Init(TIM_HandleTypeDef *htim, uint32_t channel);
void BUZZER_StartFreq();
void BUZZER_StopFreq(void);
void BUZZER_GenFreq(uint16_t freq);
void BUZZER_ModeButtonSound(void);
void BUZZER_SpeedButtonSound(void);
void BUZZER_ClickSound(void);
void BUZZER_FailSound(void);


#endif /* DRIVER_BUZZER_H_ */
