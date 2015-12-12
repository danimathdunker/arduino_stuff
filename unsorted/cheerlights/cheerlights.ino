/*  cheerlights - reads three values (0-255) RGB from serial.
 *                values shall be received on Raspberry from
 *                cheerlights.
 *                Format: rrrgggbbb#
 *
 *  2015-12-12   Andreas Dunker   created
 *
 **********************************************************************/

#include <Adafruit_NeoPixel.h>

#define PIN        6
#define NUMLEDS    1
#define BRIGHT   200

Adafruit_NeoPixel strip = Adafruit_NeoPixel (NUMLEDS, PIN, NEO_RGB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

String inputString = "";
boolean stringComplete = false;

void setup ()
{
    strip.begin ();
    strip.setBrightness (BRIGHT);
    strip.show (); // Initialize all pixels to 'off'
    Serial.begin (9600);
    Serial.println ("Start");
    inputString.reserve (20);
        strip.setPixelColor (0, 255, 0, 0);
        strip.show ();
        delay (1000);
        strip.setPixelColor (0, 0, 255, 0);
        strip.show ();
        delay (1000);
        strip.setPixelColor (0, 0, 0, 255);
        strip.show ();
        delay (1000);
}

void loop ()
{
    int r, g, b;
    serialEvent ();
    if (stringComplete)
    {
//        Serial.println (inputString);
        // clear the string:
        r = inputString.substring (0, 3).toInt ();
        g = inputString.substring (3, 6).toInt ();
        b = inputString.substring (6, 9).toInt ();
        strip.setPixelColor (0, r, g, b);
        strip.show ();
        inputString = "";
        stringComplete = false;
    }    
}

void serialEvent ()
{
    while (Serial.available ())
    {
        // get the new byte:
        char inChar = (char) Serial.read ();
        // add it to the inputString:
        inputString += inChar;
        // if the incoming character is a newline, set a flag
        // so the main loop can do something about it:
        if (inChar == '#')
        {
            stringComplete = true;
        }
    }
}


