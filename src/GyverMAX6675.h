/*
    Лёгкая библиотека для драйвера термопары MAX6675
    GitHub: https://github.com/GyverLibs/GyverMAX6675
    Возможности:
    - Чтение температуры в градусах Цельсия
	- Вывод в целых числах и float
	- Определение наличия модуля и термопары на связи
	- Работа через программный и аппаратный SPI (отдельный класс)
    
    Nich1con, AlexGyver, alex@alexgyver.ru
    https://alexgyver.ru/
    MIT License

    Версии:
    v1.0 - релиз
*/

#ifndef _GyverMAX6675_h
#define _GyverMAX6675_h
#include "Arduino.h"

template <const uint8_t M_CLK, const uint8_t M_DAT, const uint8_t M_CS>
class GyverMAX6675 {
public:
	// Конструктор
	GyverMAX6675() {
		pinMode(M_DAT, INPUT_PULLUP);	// Data как вход с подтяжкой
		pinMode(M_CLK, OUTPUT);			// Clock как выход
		pinMode(M_CS, OUTPUT);			// Chip select как выход
		digitalWrite(M_CS, HIGH);		// Подтягиваем CS к питанию
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
		for (int i = 0; i < 16; i++) {
			digitalWrite(M_CLK, HIGH);
#ifdef MAX6675_DELAY
			delayMicroseconds(MAX6675_DELAY);
#endif
			data <<= 1;
			if (digitalRead(M_DAT)) data |= 1;
			digitalWrite(M_CLK, LOW);
#ifdef MAX6675_DELAY
			delayMicroseconds(MAX6675_DELAY);
#endif
		}
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