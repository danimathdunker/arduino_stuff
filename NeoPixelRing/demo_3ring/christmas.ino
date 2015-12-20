/*  christmas - red and green
 *
 *  2015-07-08   Andreas Dunker   created
 *
 **********************************************************************/

const int CHRISTMASDELAY = 250;

void christmas ()
{
    byte numblinks = random (15) + 15;
    for (byte blink = 0;   blink < numblinks;   blink++)
    {
        for (byte led = 0;   led < NUMLEDS;   led++)
        {
            if ((led % 2) == 0)
                strip.setPixelColor (led, 255, 0, 0);
            else
                strip.setPixelColor (led, 0, 255, 0);
        }
        strip.show ();
        delay (CHRISTMASDELAY);
        for (byte led = 0;   led < NUMLEDS;   led++)
        {
            if ((led % 2) == 0)
                strip.setPixelColor (led, 0, 255, 0);
            else
                strip.setPixelColor (led, 255, 0, 0);
        }
        strip.show ();
        delay (CHRISTMASDELAY);
    }
    for (byte j = 0;   j < NUMLEDS;   j++)
    {
            strip.setPixelColor (j, 0, 0, 0);
    }
}
