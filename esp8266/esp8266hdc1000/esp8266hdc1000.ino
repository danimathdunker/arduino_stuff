/*
 *  esp8266hdc1000 - reading an HDC1000/HDC1008 sensor from ESP8266
 *
 *  2016-08-24   Andreas Dunker   crested
 *
************************************************************************/

#include <Wire.h>
#include "Adafruit_HDC1000.h"

// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (A5 on UNO, 17 (GPIO14) an ESP8266)
// Connect SDA to I2C data pin (A4 on UNO, 20 (GPIO2) an ESP8266)

Adafruit_HDC1000 hdc = Adafruit_HDC1000();

const int led = 5;
int ledstate = 0;

void setup ()
{
    delay (1000);
    pinMode (led, OUTPUT);
    Serial.begin(115200);
    Serial.println("HDC100x test");

    Wire.begin (2, 14);

    if (!hdc.begin ())
    {
        Serial.println ("Couldn't find sensor!");
        while (1);
    }
}


void loop ()
{
    ledstate = ! ledstate;
    digitalWrite (led, ledstate);

    Serial.print ("Temp: "); Serial.print(hdc.readTemperature());
    Serial.print ("\t\tHum: "); Serial.println(hdc.readHumidity());
    delay (1000);
}
