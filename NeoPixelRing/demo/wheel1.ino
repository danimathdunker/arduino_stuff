/*  wheel1 - colour wheel
 *
 *  2014-07-12   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYWHEEL1 10000

void wheel1 ()
{
    int colours [3];
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        hsb2rgb (j*(360/NUMLEDS), 255, 255, colours);
        strip.setPixelColor (j, colours [0], colours [1], colours [2]);
    }
    strip.show ();
    delay (DELAYWHEEL1);
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        strip.setPixelColor (j, 0, 0, 0);
    }
    strip.show ();
}
