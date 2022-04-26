#include "forkLift_Controller.h"

uint8_t forkLiftRunStopState;
uint8_t stepMotorState;


void forkLift_SetState(uint8_t state) {
	forkLiftRunStopState = state;
}

void stepMotor_SetState(uint8_t state) {
	stepMotorState = state;
}

void forkLift_Controller_Init(void) {
	forkLiftRunStopState = STOP;
	stepMotorState = MOTOR_STOP;
}

void stepMotor_ISR_Process() {
	switch(stepMotorState) {
		case MOTOR_STOP:
			break;
		case MOTOR_UP:
			stepMotor_CW();
			break;
		case MOTOR_DOWN:
			stepMotor_CCW();
			break;
		default :
			break;
	}
}

void forkLift_Control_Stop() {
	stepMotor_Stop();
}

void forkLift_Control_Run() {
	stepMotor_Run();
	stepMotor_Control_Dir();
}

void stepMotor_Control_Dir(void) {
	switch (stepMotorState) {
		case MOTOR_STOP:
			stepMotor_EventHandler(MOTOR_STOP);
			break;
		case MOTOR_UP:
			stepMotor_EventHandler(MOTOR_UP);
			break;
		case MOTOR_DOWN:
			stepMotor_EventHandler(MOTOR_DOWN);
			break;
		case MOTOR_MIN:
			stepMotor_MinMaxHandler(MOTOR_MIN);
			break;
		case MOTOR_MAX:
			stepMotor_MinMaxHandler(MOTOR_MAX);
			break;
	}
}

void forkLift_Controller(void) {
	switch(forkLiftRunStopState) {
		case STOP:
			forkLift_Control_Stop();
			forkLift_EventHandler(STOP);
			break;
		case RUN:
			forkLift_Control_Run();
			forkLift_EventHandler(RUN);
			break;
	}
}
