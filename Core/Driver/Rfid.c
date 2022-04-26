#include "rfid.h"

uint8_t str[MAX_LEN];


void Rfid_Init(void) {
	uint8_t byte;

	mfrc522_init(&hspi1);
	byte = mfrc522_read(VersionReg);

	printf("ver: %0x\n", byte);

	if(byte == 0x92) {
		printf("MIFARE RC522v1\n");
		printf("Detected!\n");
	}
	else printf("No reader found\n");
}

uint8_t Rfid_IsDetectCard(void) {
	uint8_t byte;
	uint8_t str[MAX_LEN];

	byte = mfrc522_request(PICC_REQALL, str);

	if (byte == CARD_FOUND)
		return TRUE;

	return FALSE;
}

void Rfid_GetCardNumber(uint8_t *str) {
	mfrc522_get_card_serial(str);
}

uint8_t Rfid_ChkUser(void) {
	if (Rfid_IsDetectCard()) {
		Rfid_GetCardNumber(str);

		for (int i = 0; i < 5; i++)
			printf("0x%02x ", str[i]);
		printf("\n");

		if (Rfid_DB_CheckNumber(str)) {
			printf("Valid User!\n");
			return VALID;
		} else {
			printf("Invalid User!\n");
			return -1;
		}
	} else
		return FALSE;
}

