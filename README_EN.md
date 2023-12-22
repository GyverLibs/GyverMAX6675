This is an automatic translation, may be incorrect in some places. See sources and examples!

# Gyvermax6675
Light library for the driver of thermocouple Max6675
- Reading temperature in degrees Celsius
- Conclusion in integers and Float
- determination of the presence of a module and thermocouple in touch
- work through software and hardware SPI (separate class)

## compatibility
Compatible with all arduino platforms (used arduino functions)

## Content
- [installation] (# Install)
- [initialization] (#init)
- [use] (#usage)
- [Example] (# Example)
- [versions] (#varsions)
- [bugs and feedback] (#fedback)

<a id="install"> </a>
## Installation
- For work, you need [gyvergfx] (https://github.com/gyverlibs/gyvergfx)
- The library can be found by the name ** gyvermax6675 ** and installed through the library manager in:
    - Arduino ide
    - Arduino ide v2
    - Platformio
- [download library] (https://github.com/gyverlibs/gyvermax6675/archive/refs/heads/main.zip). Zip archive for manual installation:
    - unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
    - unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
    - unpack and put in *documents/arduino/libraries/ *
    - (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!


<a id="init"> </a>
## initialization
`` `CPP
Gyvermax6675 <clk_pin, data_pin, cs_pin> sens;// Software SPI
Gyvermax6675_spi <cs_pin> sens;// Hardware SPI
`` `

<a id="usage"> </a>
## Usage
`` `CPP
Bool Readtemp ();// Request the temperature (will return true if successfully)
Float gettemp ();// get the temperature float
int Gettempint ();// get the temperature int

// Settings before connecting the library
// Set the CLK switching delay in microseconds to improve communication by long wires
// (for gyvermax6675)
#define max6675_Delay 10

// Set the SPI speed in Hz (default 1,000,000 - 1 MHz) to improve the connection by long wires
// (for gyvermax6675_spi)
#define max6675_spi_Speed 300000
`` `

### Peculiarities
There are two ways to obtain temperature from the sensor:
- Call `gettemp ()` or `gettempint ()` - the function will read and return the temperature from the sensor.When reading an error, the previous successfully read value will return.
- Call `Readtemp ()` - will return `true` with successful reading and` false` with an error.The result can be taken from `gettemp ()` or `gettempint ()`.

<a id="EXAMPLE"> </a>
## Example
The rest of the examples look at ** Examples **!
`` `CPP
#include <gyvermax6675.h>

// Pins of the module max6675k
#define clk_pin 13 // PINSCK
#define Data_pin 12 // PIN SO
#define cs_pin 10 // PIN CS

// Specify pins in order sck so cs
Gyvermax6675 <clk_pin, data_pin, cs_pin> sens;

VOID setup () {
  Serial.Begin (9600);
}

VOID loop () {
  if (Sens.Readtemp ()) {// Read the temperature
    Serial.print ("TEMP:");// if the reading has passed successfully - we display in Serial
    Serial.print (Sens.gettemp ());// Take the temperature through Gettemp
    //Serial.print (Sens.gettempint ());// or gettempint - integers (without Float)
    Serial.println (" *c");
  } Else serial.println ("error");// Reading or connection error - we display a log
  
  DELAY (1000);// We will wait a bit
}
`` `

<a id="versions"> </a>
## versions
- v1.0 - release

<a id="feedback"> </a>
## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!


When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- whether the built -in examples work correctly, in which the functions and designs are used, leading to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code