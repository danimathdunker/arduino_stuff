/*  random1 - all random colors
 *
 *  2015-06-19   Andreas Dunker   created
 *
 **********************************************************************/

void random1 ()
{
    int colours [3];
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        hsb2rgb (random (360), 255, 255, colours);
        strip.setPixelColor (j, colours [0], colours [1], colours [2]);
    }
    strip.show ();
    delay (10000);
}
