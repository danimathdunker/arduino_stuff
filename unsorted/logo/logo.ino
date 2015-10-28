/*  logo.ino - sketch fr animation of the Arduino Hannover Logo
 *
 *  2015-10-18   Andreas Dunker   created
 *
 **********************************************************************/

#include <Adafruit_NeoPixel.h>

const int eyes_pin   = 12;  // pin for the eyes
const int eyes_num   =  2;  // number of eyes

const int back_pin   =  7;  // pin for the back LEDs
const int back_num   =  3;  // number of back LEDs

const int min_blink =  10000;
const int max_blink =  20000;
const int dur_blink =     60;
const int hue_change =  1500;

unsigned long eyes_old_millis = 0;
unsigned long hue_old_millis = 0;
unsigned long back_old_millis = 0;

int eyes_interval;
int back_interval;

int eyes_hue = 0;
int back_hue = 0;
int col [3];

Adafruit_NeoPixel eyes = Adafruit_NeoPixel (eyes_num, eyes_pin, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel back = Adafruit_NeoPixel (back_num, back_pin, NEO_RGB + NEO_KHZ800);

void setup ()
{
/*
 *  1. init stuff
 *  =============
 */
    eyes.begin ();
    eyes.setBrightness (80);
    eyes.show ();
    back.begin ();
    back.setBrightness (255);
    back.show ();
    randomSeed (analogRead (0));
    eyes_interval = random (min_blink, max_blink);
    back_interval = 10000;
/*
 *  2. boot the eyes
 *  ================
 */
    for (byte j = 0;   j < 255;   j++)
    {
        hsb2rgb (359, 255, j, col);
        eyes.setPixelColor (0, col [0], col [1], col [2]);
        eyes.show ();
        delay (20);
    }
    for (byte j = 0;   j < 255;   j++)
    {
        hsb2rgb (359, 255, j, col);
        eyes.setPixelColor (1, col [0], col [1], col [2]);
        eyes.show ();
        delay (20);
    }
/*
 *  3. boot the back
 *  ================
 */
    for (int i = 0;   i < back_num;   i++)
    {
        int h = random (360);
        for (byte j = 0;   j < 255;   j++)
        {
            hsb2rgb (h, 255, j, col);
            back.setPixelColor (i, col [0], col [1], col [2]);
            back.show ();
            delay (20);
        }
    }
    delay (1000);    
}


void loop ()
{
/*
 *  1. handle the eyes
 *  ==================
 *  1.1. set color
 *  --------------
 */
    unsigned long currentMillis = millis ();
    if (currentMillis - hue_old_millis > hue_change)
    {
        hsb2rgb (eyes_hue, 255, 255, col);
        eyes.setPixelColor (0, col [0], col [1], col [2]);
        eyes.setPixelColor (1, col [0], col [1], col [2]);
        eyes.show ();
        hue_old_millis = currentMillis;
        eyes_hue++;
        if (eyes_hue > 359) eyes_hue = 0;
    }
/*
 *  1.2. blink
 *  ----------
 */
    if (currentMillis - eyes_old_millis > eyes_interval)
    {
        eyes_old_millis = currentMillis;
        eyes_interval = random (min_blink, max_blink);

        eyes.setPixelColor (0, 0, 0, 0);
        eyes.setPixelColor (1, 0, 0, 0);
        eyes.show ();
        delay (dur_blink);
        eyes.setPixelColor (0, col [0], col [1], col [2]);
        eyes.setPixelColor (1, col [0], col [1], col [2]);        
        eyes.show ();
    }
/*
 *  2. handle back
 *  ==============
 */
    if (currentMillis - back_old_millis > back_interval)
    {
        back_hue = random (359);
        hsb2rgb (back_hue, 255, 255, col);
        back.setPixelColor (random (back_num), col [0], col [1], col [2]);
        back.show ();
        back_old_millis = currentMillis;
    }
}
