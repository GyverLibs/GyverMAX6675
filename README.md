[![Foo](https://img.shields.io/badge/Version-1.0-brightgreen.svg?style=flat-square)](#versions)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD$%E2%82%AC%20%D0%9D%D0%B0%20%D0%BF%D0%B8%D0%B2%D0%BE-%D1%81%20%D1%80%D1%8B%D0%B1%D0%BA%D0%BE%D0%B9-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-brightgreen.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/GyverMAX6675?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)


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
### Обновление
- Рекомендую всегда обновлять библиотеку: в новых версиях исправляются ошибки и баги, а также проводится оптимизация и добавляются новые фичи
- Через менеджер библиотек IDE: найти библиотеку как при установке и нажать "Обновить"
- Вручную: **удалить папку со старой версией**, а затем положить на её место новую. "Замену" делать нельзя: иногда в новых версиях удаляются файлы, которые останутся при замене и могут привести к ошибкам!


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

### Особенности
Есть два способа получения температуры с датчика:
- Вызвать `getTemp()` или `getTempInt()` - функция прочитает и вернёт температуру с датчика. При ошибке чтения вернёт предыдущее успешно прочитанное значение.
- Вызвать `readTemp()` - вернёт `true` при успешном чтении и `false` при ошибке. Результат можно забрать из `getTemp()` или `getTempInt()`.

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


При сообщении о багах или некорректной работе библиотеки нужно обязательно указывать:
- Версия библиотеки
- Какой используется МК
- Версия SDK (для ESP)
- Версия Arduino IDE
- Корректно ли работают ли встроенные примеры, в которых используются функции и конструкции, приводящие к багу в вашем коде
- Какой код загружался, какая работа от него ожидалась и как он работает в реальности
- В идеале приложить минимальный код, в котором наблюдается баг. Не полотно из тысячи строк, а минимальный код
