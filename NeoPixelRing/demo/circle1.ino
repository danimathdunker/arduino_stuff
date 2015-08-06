/*  circle1 - circles one pixel with HSB colour
 *
 *  2014-07-12   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYCIRCLE1 20

void circle1 ()
{
    int colours [3];
    int numcircles;

    numcircles = random (10) + 20;
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

            hsb2rgb (j*6, 255, 255, colours); // WTF have I done here?
            strip.setPixelColor (j, colours [0], colours [1], colours [2]);
            strip.show ();
            delay (DELAYCIRCLE1);
        }
    }
    strip.setPixelColor (NUMLEDS-1, 0, 0, 0);
}
