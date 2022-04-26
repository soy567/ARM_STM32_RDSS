#ifndef DRIVER_SPI_H_
#define DRIVER_SPI_H_

#include "main.h"

typedef struct {
	SPI_HandleTypeDef *hspi;
	GPIO_TypeDef *GPIO;
	uint16_t  GPIO_Pin;
} SPI_CONTROL_HandleTypeDef;

extern SPI_CONTROL_HandleTypeDef hSpiFnd;
extern SPI_CONTROL_HandleTypeDef hSpiRfid;

void SPI_Init(SPI_CONTROL_HandleTypeDef *hSpi, SPI_HandleTypeDef *hspi);
void SPI_WriteByte(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t data);
void SPI_WriteStream(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t *data, uint16_t Size);
uint8_t SPI_ReadByte(SPI_CONTROL_HandleTypeDef *hSpi);
void SPI_ReadStream(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t *data, uint16_t Size);
uint8_t SPI_TranceiveByte(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t txData);
void SPI_TranceiveStream(SPI_CONTROL_HandleTypeDef *hSpi, uint8_t *txData, uint8_t *rxData, uint16_t Size);


#endif /* DRIVER_SPI_H_ */
