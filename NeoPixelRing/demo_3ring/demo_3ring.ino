/*  demo_3ring - several patterns for three Watterott (or
 *               NeoPixel) rings
 *               ring 1: 16 LEDs
 *               ring 2: 24 LEDs
 *               ring 3: 36 LEDs
 *
 *  2015-06-13   Andreas Dunker   created
 *
 **********************************************************************/

#define DEBUG

#include <Adafruit_NeoPixel.h>

#define PIN        6
#define NUMINNER  16
#define NUMMIDDL  24
#define NUMOUTER  32
#define BRIGHT    15
#define DELAY     25
#define NUMFUNCS   7

const int NUMLEDS = NUMINNER + NUMMIDDL + NUMOUTER;
Adafruit_NeoPixel strip = Adafruit_NeoPixel (NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

float redStates   [NUMLEDS];
float blueStates  [NUMLEDS];
float greenStates [NUMLEDS];
float fadeRate = 0.96;

void setup ()
{
#ifdef DEBUG
    Serial.begin (115200);
#endif
    strip.begin ();
    strip.setBrightness (BRIGHT);
    strip.show (); // Initialize all pixels to 'off'
    randomSeed (analogRead (0));

    blinkwhite ();
    blinkcol ();
    windmill ();
    christmas ();
    fill ();
    random1 ();
    wheel1 ();
}

void loop ()
{
    int func = random (NUMFUNCS);
    switch (func)
    {
        case 6:
            blinkwhite ();
            break;
        case 5:
            blinkcol ();
            break;
        case 4:
            windmill ();
            break;
        case 3:
            christmas ();
            break;
        case 2:
            fill ();
            break;
        case 1:
            random1 ();
            break;
        case 0:
            wheel1 ();
            break;
    }
    
}

