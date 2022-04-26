#ifndef CONTROLLER_FORKLIFT_CONTROLLER_H_
#define CONTROLLER_FORKLIFT_CONTROLLER_H_

#include "main.h"
#include "forkLift_EventController.h"
#include "../Driver/stepMotor.h"
#include "../Driver/Bluetooth.h"

enum {STOP, RUN};
enum {MOTOR_STOP, MOTOR_UP, MOTOR_DOWN, MOTOR_MAX, MOTOR_MIN};

void forkLift_SetState(uint8_t state);
void stepMotor_SetState(uint8_t state);
void forkLift_Controller_Init(void);
void stepMotor_ISR_Process();
void forkLift_Control_Stop();
void forkLift_Control_Run();
void stepMotor_Control_Dir(void);
void forkLift_Controller(void);


#endif /* CONTROLLER_FORKLIFT_CONTROLLER_H_ */
