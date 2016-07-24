/*  clockwork.ino - RGBdigit clock with HDC 1008 (temperature & humidity)
 *
 *  2016-06-15   Andreas Dunker   created
 *
 **********************************************************************/

#include <RGBDigit.h>            // the RGBDigits themselves
#include <DS3231.h>              // RTC
#include "Wire.h"                // Standard I2C
#include <Adafruit_NeoPixel.h>   // controlling the Neopixels
#include "Adafruit_HDC1000.h"    // temperature & humidity sensor with I2C

#define NDIGITS 4

RGBDigit rgbDigit (NDIGITS);       // uses default pin 12
DS3231   Clock;

const int PIN    = 12;  // Sending neopixel data to Pin 12
const int VPIN   =  7;  // switch LDR on/off
const int LDRPIN = A1;  // read LDR
bool Run_blink = 0;

const byte FALSE = 0;
const byte TRUE  = 1;

int colour_hour     = 0;
int colour_minute   = 0;
int colour_dp_left  = 0;
int colour_dp_right = 0;
int colour_temp     = 0;
int colour_humi     = 0;

float fTemperature = -99.0;
float fHumidity    = 888.0;

byte hours, minutes, seconds;

byte animation = FALSE;

Adafruit_NeoPixel strip = Adafruit_NeoPixel (32, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_HDC1000  hdc   = Adafruit_HDC1000 ();

void setup ()
{
	randomSeed (analogRead (0));
    rgbDigit.begin ();
    rgbDigit.clearAll ();
    Clock.setClockMode (FALSE);
    Serial.begin (115200);

    if (!hdc.begin ())
    {
        Serial.println ("Couldn't find sensor!");
        while (1)
        {
//        	Blink_DP ();
        	delay (1000);
        }
    }
    colour_hour     = random (360);
    colour_minute   = random (360);
    colour_dp_left  = random (360);
    colour_dp_right = random (360);
    colour_temp     = random (360);
    colour_humi     = random (360);

    animate ();
}

void loop ()
{
	int bright = 100;

	delay (930);    // +/-1 second interval
    Serial.print ("Main loop "); Serial.println (millis ());

    read_clock ();
    if (animation && ((minutes == 0) || (minutes == 30)))
    {
    	animate ();
    	read_clock ();
    	animation = FALSE;
    	rgbDigit.showDot (0, 0, 0, 0);
    	rgbDigit.showDot (3, random (100), random (100), random (100));
    }
    if (((minutes == 15) || (minutes == 45)) && (! animation))
    {
    	animation = TRUE;
    	rgbDigit.showDot (0, random (100), random (100), random (100));
    	rgbDigit.showDot (3, 0, 0, 0);
    }
    read_temp ();
    read_humi ();
    
    Serial.print ("### ");Serial.print (hours); Serial.print (":"); Serial.print (minutes); Serial.print (":"); Serial.println (seconds);

    digitalWrite (VPIN, HIGH);          // start measurement
    delay (20);                         // let the LDR settle
    bright = analogRead (LDRPIN);       // read value
    digitalWrite (VPIN, LOW);           // stop measurement
    rgbDigit.setBrightness (bright/4);  // set brightness

    if ((seconds < 6) || ((seconds > 30) && (seconds < 36)))
    {
        show_temp ();
    }
    else if ((seconds < 11) || ((seconds > 35) && (seconds < 41)))
    {
        show_humi ();
    }
    else
    {
	    show_clock ();
    }
}


