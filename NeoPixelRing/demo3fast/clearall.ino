/*  clearall - clears all LEDs
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

void clearall ()
{
    for (int j = 0;   j < NUM_LEDS;   j++)
    {
        leds [j] = CRGB::Black;
    }
    FastLED.show ();
}
