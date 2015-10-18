/*  fill1 - fills the whole rings
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

const int FILL1DELAY = 50;
byte fill1loops = random (5) + 5;

void fill1 ()
{
    for (byte j = 0;   j < fill1loops;   j++)
    {
        uint8_t hue = random (255);
        for (byte led = 0;   led < NUM_LEDS;   led++)
        {
            leds [led] = CHSV (hue, 255, 255);
            FastLED.show ();
            delay (FILL1DELAY);
        }
    }
    clearall ();
}
