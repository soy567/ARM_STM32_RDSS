#ifndef CONTROLLER_FORKLIFT_EVENTCONTROLLER_H_
#define CONTROLLER_FORKLIFT_EVENTCONTROLLER_H_

#include "main.h"
#include <stdio.h>
#include "forkLift_Controller.h"
#include  "../Driver/Button.h"
#include "../Driver/Rfid.h"
#include "../Driver/I2C_LCD.h"


void forkLift_EventHandler(uint8_t state);
void stepMotor_EventHandler(uint8_t state);
void stepMotor_MinMaxHandler(uint8_t state);


#endif /* CONTROLLER_FORKLIFT_EVENTCONTROLLER_H_ */
