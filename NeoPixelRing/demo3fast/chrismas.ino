/*  christmas - blink red and green
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYRG 200

void christmas ()
{
    int numloops = random (50) + 10;
    for (int j = 0;   j < numloops;   j++)
    {
        for (int led = 0;   led < NUM_LEDS;  led++)
        {
            if ((led % 2) == 0)
                leds [led] = CRGB::DarkRed;
            else
                leds [led] = CRGB::DarkGreen;
        }
        FastLED.show ();
        delay (DELAYRG);
        for (int led = 0;   led < NUM_LEDS;  led++)
        {
            if ((led % 2) == 0)
                leds [led] = CRGB::DarkGreen;
            else
                leds [led] = CRGB::DarkRed;
        }
        FastLED.show ();
        delay (DELAYRG);
    }
    clearall ();
}

