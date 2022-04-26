#include "i2c.h"


I2C_Control_HandleTypeDef hI2C_LCD = {&hi2c1, 0x27<<1};

void I2C_TxByte(I2C_Control_HandleTypeDef *hi2c, uint8_t data) {
	HAL_I2C_Master_Transmit(hi2c->hi2c, hi2c->DevAddress, &data, 1, 1000);
}

uint8_t I2C_RxByte(I2C_Control_HandleTypeDef *hi2c) {
	uint8_t rxData;

	HAL_I2C_Master_Receive(hi2c->hi2c, hi2c->DevAddress, &rxData, 1, 1000);
	return rxData;
}

void I2C_TxStream(I2C_Control_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size) {
	HAL_I2C_Master_Transmit(hi2c->hi2c, hi2c->DevAddress, pData, Size, 1000);
}

void I2C_RxStream(I2C_Control_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size) {
	HAL_I2C_Master_Receive(hi2c->hi2c, hi2c->DevAddress, pData, Size, 1000);
}
