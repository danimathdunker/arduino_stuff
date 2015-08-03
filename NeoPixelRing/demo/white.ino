/*  white - fade white
 *
 *  2014-12-13   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYWHITE  50
#define MAXBRIGHT  25

void white ()
{
    int numloops = random (10) + 5;
    for (int a = 0;   a < numloops;   a++)
    {
        for (int j = 0;   j < MAXBRIGHT;   j++)
        {
            for (int l = 0;   l < NUMLEDS;  l++)
           {
                strip.setPixelColor (l, 255, 255, 255);
                strip.setBrightness (j);
            }
            strip.setBrightness (j);
            strip.show ();
            delay (DELAYWHITE);
        }
        for (int j = MAXBRIGHT;   j >= 0;   j--)
        {
            for (int l = 0;   l < NUMLEDS;  l++)
            {
                strip.setPixelColor (l, 255, 255, 255);
            }
            strip.setBrightness (j);
            strip.show ();
            delay (DELAYWHITE);
        }
    }
    strip.setBrightness (BRIGHT);

}
