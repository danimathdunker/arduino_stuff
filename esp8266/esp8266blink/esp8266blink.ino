/*********
 * 
 *   test.ino - some tests with ESSP8266
 *   
 *   2016-08-24   Andreas Dunker   created
 *   
 * based on:
 * Rui Santos
 * Complete project details at http://randomnerdtutorials.com  
 *********/

#include <ESP.h>

const int pin = 5;
const int DELAY = 1000;

ADC_MODE(ADC_VCC);

void setup ()
{
    // initialize GPIO 5 as an output.
    pinMode (pin, OUTPUT);
    Serial.begin (115200);
}

// the loop function runs over and over again forever
void loop ()
{
	Serial.print (ESP.getVcc ()); Serial.println (" mV");
	Serial.println ("on");
    digitalWrite (pin, HIGH);     // turn the LED on (HIGH is the voltage level)
    delay (DELAY);               // wait for a second
	Serial.println ("off");
    digitalWrite (pin, LOW);     // turn the LED off by making the voltage LOW
    delay (DELAY);               // wait for a second
}
