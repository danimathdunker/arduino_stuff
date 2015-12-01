/*  fill - fills the whole rings
 *
 *  2015-07-08   Andreas Dunker   created
 *
 **********************************************************************/

const int FILLDELAY = 75;
byte numfills = random (10) + 5;

void fill ()
{
    int colours [3];
    for (byte j = 0;   j < numfills;   j++)
    {
        hsb2rgb (random (360), 255, 255, colours);
        for (byte led = 0;   led < NUMLEDS;   led++)
        {
            strip.setPixelColor (led, colours [0], colours [1], colours [2]);
            strip.show ();
            delay (FILLDELAY);
        }
    }
    for (byte led = 0;   led < NUMLEDS;   led++)
    {
        strip.setPixelColor (led, 0, 0, 0);
        strip.show ();
        delay (FILLDELAY);
    }
}

