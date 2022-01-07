![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![author](https://img.shields.io/badge/author-AlexGyver-informational.svg)
# GyverMAX6675
Лёгкая библиотека для драйвера термопары MAX6675
- Чтение температуры в градусах Цельсия
- Вывод в целых числах и float
- Определение наличия модуля и термопары на связи
- Работа через программный и аппаратный SPI (отдельный класс)

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Использование](#usage)
- [Пример](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Для работы нужна [GyverGFX](https://github.com/GyverLibs/GyverGFX)
- Библиотеку можно найти по названию **GyverMAX6675** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/GyverMAX6675/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
```cpp
GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;   // программный SPI
GyverMAX6675_SPI<CS_PIN> sens;                  // аппаратный SPI
```

<a id="usage"></a>
## Использование
```cpp
bool readTemp();		// Запросить температуру (вернёт true если успешно)
float getTemp();		// Получить температуру float
int getTempInt();		// Получить температуру int

// Настройки перед подключением библиотеки
// задать задержку переключения CLK в микросекундах для улучшения связи по длинным проводам
// (для GyverMAX6675)
#define MAX6675_DELAY 10

// задать скорость SPI в Гц (умолч. 1000000 - 1 МГц) для улучшения связи по длинным проводам
// (для GyverMAX6675_SPI)
#define MAX6675_SPI_SPEED 300000
```

<a id="example"></a>
## Пример
Остальные примеры смотри в **examples**!
```cpp
#include <GyverMAX6675.h>

// Пины модуля MAX6675K
#define CLK_PIN   13  // Пин SCK
#define DATA_PIN  12  // Пин SO
#define CS_PIN    10  // Пин CS

// указываем пины в порядке SCK SO CS
GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (sens.readTemp()) {            // Читаем температуру
    Serial.print("Temp: ");         // Если чтение прошло успешно - выводим в Serial
    Serial.print(sens.getTemp());   // Забираем температуру через getTemp
    //Serial.print(sens.getTempInt());   // или getTempInt - целые числа (без float)
    Serial.println(" *C");
  } else Serial.println("Error");   // ошибка чтения или подключения - выводим лог
  
  delay(1000);                      // Немного подождем
}
```

<a id="versions"></a>
## Версии
- v1.0 - релиз

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!