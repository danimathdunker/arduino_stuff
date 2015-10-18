/*  fill2 - fills and clears the whole rings
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

const int FILL2DELAY = 30;
byte fill2loops = random (5) + 5;

void fill2 ()
{
    int colours [3];
    for (byte j = 0;   j < fill2loops;   j++)
    {
        uint8_t hue2 = random (255);
        for (byte led = 0;   led < NUM_LEDS;   led++)
        {
            leds [led] = CHSV (hue2, 255, 255);
            FastLED.show ();
            delay (FILL2DELAY);
        }
        uint8_t hue = random (255);
        for (byte led = 0;   led < NUM_LEDS;   led++)
        {
            leds [led] = CRGB::Black;
            FastLED.show ();
            delay (FILL2DELAY);
        }
    }
    clearall ();
}
