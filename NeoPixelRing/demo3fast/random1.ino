/*  random1 - all random colors
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

void random1 ()
{
    for (int j = 0;   j < NUM_LEDS;   j++)
    {
        leds [j] = CHSV (random (255), 255, 255);
    }
    FastLED.show ();
    delay (10000);
    clearall ();
}

