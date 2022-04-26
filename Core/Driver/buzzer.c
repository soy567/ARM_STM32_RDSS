#include "buzzer.h"


TIM_HandleTypeDef *hBuzzTim; // buzzer timer
uint32_t buzzChannel;		// buzzer timer channel


void BUZZER_Init(TIM_HandleTypeDef *htim, uint32_t channel) {
	hBuzzTim = htim;
	buzzChannel = channel;
}

void BUZZER_StartFreq() {
	// PWM Start
	HAL_TIM_PWM_Start(hBuzzTim, buzzChannel);
	// PWM 시작 시마다 count = 0으로 세팅
	// __HAL_TIM_SET_COUNTER(hBuzzTim, 0);
}

void BUZZER_StopFreq(void) {
	// PWM Stop
	HAL_TIM_PWM_Stop(hBuzzTim, buzzChannel);
}

void BUZZER_GenFreq(uint16_t freq) {
	uint16_t arr = (100000/freq) - 1;
	uint16_t crr = arr/2;
	__HAL_TIM_SET_AUTORELOAD(hBuzzTim, arr);
	__HAL_TIM_SET_COMPARE(hBuzzTim, buzzChannel, crr);
}

void BUZZER_ModeButtonSound(void) {
	// make sound -> Repeat(make freq -> delay) -> no sound
	BUZZER_StartFreq();
	BUZZER_GenFreq(1000);
	HAL_Delay(100);
	BUZZER_GenFreq(2000);
	HAL_Delay(100);
	BUZZER_GenFreq(3000);
	HAL_Delay(100);
	BUZZER_StopFreq();
}

void BUZZER_SpeedButtonSound(void) {
	// make sound -> Repeat(make freq -> delay) -> no sound
	BUZZER_StartFreq();
	BUZZER_GenFreq(3000);
	HAL_Delay(100);
	BUZZER_GenFreq(4000);
	HAL_Delay(100);
	BUZZER_GenFreq(5000);
	HAL_Delay(100);
	BUZZER_StopFreq();
}

void BUZZER_ClickSound(void) {
	BUZZER_StartFreq();
	BUZZER_GenFreq(2000);
	HAL_Delay(100);
	BUZZER_StopFreq();
}

void BUZZER_FailSound(void) {
	BUZZER_StartFreq();
	BUZZER_GenFreq(1500);
	HAL_Delay(100);
	BUZZER_StopFreq();
}

