#ifndef DRIVER_STEPMOTOR_H_
#define DRIVER_STEPMOTOR_H_

#include "main.h"

#define STEP_A1_GPIO		GPIOC
#define STEP_A1_GPIO_PIN	GPIO_PIN_0
#define STEP_B1_GPIO		GPIOC
#define STEP_B1_GPIO_PIN	GPIO_PIN_1
#define STEP_A2_GPIO		GPIOC
#define STEP_A2_GPIO_PIN	GPIO_PIN_2
#define STEP_B2_GPIO		GPIOC
#define STEP_B2_GPIO_PIN	GPIO_PIN_3


void stepMotor_Stop(void);
void stepMotor_Run(void);
void stepMotor_Direction(uint8_t dir);
void stepMotor_CW();
void stepMotor_CCW();


#endif /* DRIVER_STEPMOTOR_H_ */
