This is an automatic translation, may be incorrect in some places. See sources and examples!

# GyverMAX6675
Lightweight library for MAX6675 thermocouple driver
- Read temperature in degrees Celsius
- Output in integers and floats
- Determination of the presence of the module and thermocouple in communication
- Work through software and hardware SPI (separate class)

### Compatibility
Compatible with all Arduino platforms (using Arduino functions)

## Content
- [Install](#install)
- [Initialization](#init)
- [Usage](#usage)
- [Example](#example)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- Requires [GyverGFX](https://github.com/GyverLibs/GyverGFX) to work
- The library can be found under the name **GyverMAX6675** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download library](https://github.com/GyverLibs/GyverMAX6675/archive/refs/heads/main.zip) .zip archive for manual installation:
    - Unzip and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unzip and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/*
    - (Arduino IDE) automatic installation from .zip: *Sketch/Include library/Add .ZIP library…* and specify the downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE% D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Initialization
```cpp
GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens; // software SPI
GyverMAX6675_SPI<CS_PIN> sens; // hardware SPI
```

<a id="usage"></a>
## Usage
```cpp
bool readTemp(); // Request temperature (returns true if successful)
float getTemp(); // Get float temperature
int getTempInt(); // Get temperature int

// Settings before connecting the library
// set CLK switching delay in microseconds to improve communication over long wires
// (for GyverMAX6675)
#define MAX6675_DELAY 10

// set SPI speed in Hz (default 1000000 - 1 MHz) to improve communication over long wires
// (for GyverMAX6675_SPI)
#define MAX6675_SPI_SPEED 300000
```

### Peculiarities
There are two ways to get the temperature from the sensor:
- Call `getTemp()` or `getTempInt()` - the function will read and return the temperature from the sensor. On a read error, it will return the previous successfully read value.
- Call `readTemp()` - will return `true` on successful read and `false` on error. The result can be taken from `getTemp()` or `getTempInt()`.

<a id="example"></a>
## Example
See **examples** for other examples!
```cpp
#include <GyverMAX6675.h>

// MAX6675K module pins
#define CLK_PIN 13 // SCK pin
#define DATA_PIN 12 // Pin SO
#define CS_PIN 10 // CS pin

// specify pins in order SCK SO CS
GyverMAX6675<CLK_PIN, DATA_PIN, CS_PIN> sens;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (sens.readTemp()) { // Read temperature
    Serial.print("Temp: "); // If the reading was successful, output to Serial
    Serial.print(sens.getTemp()); // Get the temperature via getTemp
    //Serial.print(sens.getTempInt()); // or getTempInt - integers (no floats)
    Serial.println("*C");
  } else Serial.println("Error"); // read or connect error - output log
  
  delay(1000); // Let's wait a bit
}```

<a id="versions"></a>
## Versions
- v1.0 - release

<a id="feedback"></a>
## Bugs and feedback
When you find bugs, create an **Issue**, or better, immediately write to the mail [alex@alexgyver.ru](mailto:alex@alexgyver.ru)
The library is open for revision and your **Pull Request**'s!