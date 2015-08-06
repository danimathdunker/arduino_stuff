/*  randstatic - random colors, static
 *
 *  2014-07-12   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYRANDSTATIC 5000

void randstatic ()
{
    int colours [3];
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        hsb2rgb (random (360), 255, 255, colours);
        strip.setPixelColor (j, colours [0], colours [1], colours [2]);
    }
    strip.show ();
    delay (DELAYRANDSTATIC);
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        strip.setPixelColor (j, 0, 0, 0);
    }
    strip.show ();
}
