/*  wheel1 - static colour wheel
 *
 *  2015-06-13   Andreas Dunker   created
 *
 **********************************************************************/

void wheel1 ()
{
    int colours [3];
    for (int j = 0;   j < NUMOUTER;   j++)
    {
        hsb2rgb (j*(360/NUMOUTER), 255, 255, colours);
        strip.setPixelColor (j, colours [0], colours [1], colours [2]);
    }
    for (int j = 0;   j < NUMMIDDL;   j++)
    {
        hsb2rgb (j*(360/NUMMIDDL), 255, 255, colours);
        strip.setPixelColor (j + NUMOUTER, colours [0], colours [1], colours [2]);
    }
    for (int j = 0;   j < NUMINNER;   j++)
    {
        hsb2rgb (j*(360/NUMINNER), 255, 255, colours);
        strip.setPixelColor (j + NUMOUTER + NUMMIDDL, colours [0], colours [1], colours [2]);
    }
    strip.show ();
    delay (10000);
    for (int j = 0;   j < NUMLEDS;   j++)
    {
        strip.setPixelColor (j, 0, 0, 0);
    }
    strip.show ();
}
