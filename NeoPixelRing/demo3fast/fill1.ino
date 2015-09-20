/*  fill1 - fills the whole rings
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

const int FILL1DELAY = 50;
byte num1fills = random (10) + 5;

void fill1 ()
{
    int colours [3];
    for (byte j = 0;   j < num1fills;   j++)
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
