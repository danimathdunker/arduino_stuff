/*  random2 - blink random colors
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

const int RAND2DELAY = 30;
int rand2loops = random (100) + 350;

void random2 ()
{
    for (int j = 0;   j < NUM_LEDS;   j++)
    {
        leds [j] = CHSV (random (255), 255, 255);
    }
    FastLED.show ();
    for (int j = 0;   j < rand2loops;   j++)
    {
        uint8_t led = random (NUM_LEDS);
        uint8_t hue = random (255);
        leds [led] = CHSV (hue, 255, 255);
        FastLED.show ();
        delay (RAND2DELAY);
    }
    clearall ();
}

