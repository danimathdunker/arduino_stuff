/*  demo_3ring - several patterns for three Watterott (or
 *               NeoPixel) rings with FastLED library
 *               ring 1: 16 LEDs
 *               ring 2: 24 LEDs
 *               ring 3: 36 LEDs
 *
 *  201509-20   Andreas Dunker   created
 *
 **********************************************************************/

// #define DEBUG

#include "FastLED.h"


#define DATA_PIN    6
#define NUM_INNER  16
#define NUM_MIDDL  24
#define NUM_OUTER  32
#define BRIGHT     70
#define DELAY      25
#define NUM_FUNCS   6
#define CHIPSET    WS2812B
#define COL_ORDER  GRB

const int NUM_LEDS = NUM_INNER + NUM_MIDDL + NUM_OUTER;
CRGB leds[NUM_LEDS];


// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup ()
{
#ifdef DEBUG
    Serial.begin (115200);
#endif
    FastLED.addLeds<CHIPSET, DATA_PIN, COL_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness (BRIGHT);


    randomSeed (analogRead (0));

}

void loop ()
{
/*    int func = random (NUMFUNCS);
    switch (func)
    {
        case 5:
            glow ();
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
    } */
    for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Green;
            leds[NUM_LEDS - dot] = CRGB::Red;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            leds[NUM_LEDS - dot] = CRGB::Black;
            delay(30);
        }
}

