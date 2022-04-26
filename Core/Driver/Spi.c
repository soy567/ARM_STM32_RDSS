#include "Spi.h"

SPI_CONTROL_HandleTypeDef hSpiRfid = {&hspi1, GPIOC, GPIO_PIN_7};

void SPI_Init(SPI_CONTROL_HandleTypeDef *hSpi, SPI_HandleTypeDef *hspi) {
	hSpi->hspi = hspi;
}

void SPI_WriteByte(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t data) {
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET); // slave select
	HAL_SPI_Transmit(hSpi->hspi, &data, 1, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);  // slave Deselect
}

void SPI_WriteStream(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t *data, uint16_t Size) {
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET); // slave select
	HAL_SPI_Transmit(hSpi->hspi, data, Size, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);  // slave Deselect
}

uint8_t SPI_ReadByte(SPI_CONTROL_HandleTypeDef *hSpi) {
	uint8_t rxData;

	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET); // slave select
	HAL_SPI_Receive(hSpi->hspi, &rxData, 1, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);  // slave Deselect
	return rxData;
}

void SPI_ReadStream(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t *data, uint16_t Size) {
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET); // slave select
	HAL_SPI_Receive(hSpi->hspi, data, Size, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);  // slave Deselect
}

uint8_t SPI_TranceiveByte(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t txData) {
	uint8_t rxData;

	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET); // slave select
	HAL_SPI_TransmitReceive(hSpi->hspi, &txData, &rxData, 1, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);  // slave Deselect
	return rxData;
}

void SPI_TranceiveStream(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t *txData, uint8_t *rxData, uint16_t Size) {
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_RESET); // slave select
	HAL_SPI_TransmitReceive(hSpi->hspi, txData, rxData, Size, 1000);
	HAL_GPIO_WritePin(hSpi->GPIO, hSpi->GPIO_Pin, GPIO_PIN_SET);  // slave Deselect
}


