/*  wheel - colour wheel
 *
 *  2014-07-12   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYWHHEL1 25

void wheel1 ()
{
    int colours [3];
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        hsb2rgb (j*(360/NUMLEDS), 255, 255, colours);
        strip.setPixelColor (j, colours [0], colours [1], colours [2]);
    }
    strip.show ();
    delay (10000);
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        strip.setPixelColor (j, 0, 0, 0);
    }
    strip.show ();
}
