#ifndef _GyverMAX6675_SPI_h
#define _GyverMAX6675_SPI_h

#include "Arduino.h"
#include <SPI.h>
#ifndef MAX6675_SPI_SPEED
#define MAX6675_SPI_SPEED 1000000
#endif
static SPISettings MAX6675_SETT(MAX6675_SPI_SPEED, MSBFIRST, SPI_MODE0);

template <const uint8_t M_CS>
class GyverMAX6675_SPI {
public:
	// Конструктор
	GyverMAX6675_SPI() {
		pinMode(M_CS, OUTPUT);			// Chip select как выход
		digitalWrite(M_CS, HIGH);		// Подтягиваем CS к питанию
		SPI.begin();
	}
	
	// Получить температуру float
	float getTemp() {
		if (!_flag) readTemp();			// Если чтение не выполнялось - принудительно читаем
		_flag = false;					// Сбросили флаг
		return (_buffer * 0.25);		// Вернули значение буфера
	}
	
	// Получить температуру int
	int getTempInt() {
		if (!_flag) readTemp();			// Если чтение не выполнялось - принудительно читаем
		_flag = false;					// Сбросили флаг
		return (_buffer >> 2);			// Вернули значение буфера
	}
	
	// Запросить температуру
	bool readTemp() {
		_flag = true;					// Поставили флаг, что чтение выполнялось
		uint16_t data = 0;
		digitalWrite(M_CS, LOW);		// Опустили Chip Select
		SPI.beginTransaction(MAX6675_SETT);
		data = SPI.transfer16(0);
		SPI.endTransaction();
		digitalWrite(M_CS, HIGH);		// Подняли Chip Select

		if ((data == 0xFFFF) || (data & 0b100)) return false;	// Если модуль или термопара не подключены
		_buffer = data >> 3;
		return true;
	}

private:
	bool _flag = false;		// Флаг проведенного чтения 
	uint16_t _buffer = 0;	// Буфер для температуры
};
#endif