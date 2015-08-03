/*  circle2 - circles on pixel
 *
 *  2014-07-12   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYCIRCLE2 25

void circle2 ()
{
    int colours [3];
    int numcircles;

    numcircles = random (20) + 10;
    for (int i = 0;   i < numcircles;   i++)
    {
        hsb2rgb (random (360), 255, 255, colours);
        for (int j = 0;   j < NUMLEDS;   j++)
        {
            if (j > 0)
            {
                strip.setPixelColor (j-1, 0, 0, 0);
            }
            else
            {
                strip.setPixelColor (NUMLEDS-1, 0, 0, 0);
            }
            strip.setPixelColor (j, colours [0], colours [1], colours [2]);
            strip.show ();
            delay (DELAYCIRCLE2);
        }
    }
    strip.setPixelColor (NUMLEDS-1, 0, 0, 0);
}
