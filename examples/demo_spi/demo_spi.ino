// чтение температуры (подключение к SPI)
#include <GyverMAX6675_SPI.h>

// перед подключением библиотеки можно
// задать скорость SPI в Гц (умолч. 1000000 - 1 МГц)
// для увеличения качества связи по длинным проводам
//#define MAX6675_SPI_SPEED 300000

// указываем пин CS
// остальные подключены к аппаратному SPI (SCK и MISO)
GyverMAX6675_SPI<10> sens;

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
