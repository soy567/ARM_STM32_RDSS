#ifndef DRIVER_RFID_H_
#define DRIVER_RFID_H_

#include "main.h"
#include "mfrc522.h"
#include <stdio.h>

#define TRUE		1
#define FALSE		0

#define VALID		1
#define INVALID		0

void Rfid_Init(void);
uint8_t Rfid_IsDetectCard(void);
void Rfid_GetCardNumber(uint8_t *str);
uint8_t Rfid_ChkUser(void);


#endif /* DRIVER_RFID_H_ */
