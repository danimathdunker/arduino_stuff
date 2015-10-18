/*  demo_3ring - several patterns for three Watterott (or
 *               NeoPixel) rings with FastLED library
 *               ring 1: 16 LEDs
 *               ring 2: 24 LEDs
 *               ring 3: 36 LEDs
 *
 *  201509-20   Andreas Dunker   created
 *
 **********************************************************************/


#include "FastLED.h"


#define DATA_PIN    6
#define NUM_INNER  16
#define NUM_MIDDL  24
#define NUM_OUTER  32
#define BRIGHT     30

#define CHIPSET    WS2812B
#define COL_ORDER  GRB

#define NUM_FUNCS   7



const int NUM_LEDS = NUM_INNER + NUM_MIDDL + NUM_OUTER;
CRGB leds [NUM_LEDS];

/* ##################################################### setup */
void setup ()
{
    Serial.begin (115200);

    FastLED.addLeds<CHIPSET, DATA_PIN, COL_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness (BRIGHT);

    randomSeed (analogRead (0));  // set random number generator

    inout1 ();
    windmill ();
    random2 ();
    christmas ();
    fill1 ();
    fill2 ();
    random1 ();
}

/* ###################################################### loop */
void loop ()
{
    int func = random (NUM_FUNCS);
    switch (func)
    {
        case 6:
            inout1 ();
            break;
        case 5:
            windmill ();
            break;
        case 4:
            random1 ();
            break;
        case 3:
            random2 ();
            break;
        case 2:
            fill1 ();
            break;
        case 1:
            fill2 ();
            break;
        case 0:
            christmas ();
            break;
    }
}

