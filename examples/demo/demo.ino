// чтение температуры (подключение к любым пинам)
#include <GyverMAX6675.h>

// Пины модуля MAX6675K
#define CLK_PIN   13  // Пин SCK
#define DATA_PIN  12  // Пин SO
#define CS_PIN    10  // Пин CS

// перед подключением библиотеки можно
// задать задержку переключения CLK в микросекундах
// для увеличения качества связи по длинным проводам
//#define MAX6675_DELAY 10

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
