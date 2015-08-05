#include <Adafruit_NeoPixel.h>

#define PIN        6
#define NUMLEDS   24
#define NUMFUNCS   8
#define BRIGHT    30
#define LED       13

byte ledState;

Adafruit_NeoPixel strip = Adafruit_NeoPixel (NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup ()
{
//    Serial.begin (9600);
//    Serial.println ("setup start");
    randomSeed (analogRead (0));
    pinMode (LED, OUTPUT);
    digitalWrite (LED, HIGH);
    ledState = HIGH;
    strip.begin ();
    strip.setBrightness (BRIGHT);
    strip.show (); // Initialize all pixels to 'off'

    white ();
    redgreen ();
    wheel1 ();
    circle1 ();
    randstatic ();
    circle2 ();
    randomwalk ();
}

void loop ()
{
    if (ledState == HIGH)
    {
        ledState = LOW;
    }
    else
    {
        ledState = HIGH;
    }
    digitalWrite (LED, ledState);
    
    int func = random (NUMFUNCS);
    switch (func)
    {
        case 7:
            redgreen ();
            break;
        case 6:
            white ();
            break;
        case 5:
            randomwalk ();
            break;
        case 4:
            circle1 ();
            break;
        case 3:
            wheel1 ();
            break;
        case 2:
            randstatic ();
            break;
        case 1:
            circle2 ();
            break;
        case 0:
            explosion ();
            break;
    }
}

