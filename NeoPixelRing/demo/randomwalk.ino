/*  randomwalk - one pixals walks randomly
 *
 *  2014-07-15   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYRANDOMWALK 75
#define DELTAHUE         6

void randomwalk ()
{
    int colours [3];
    int numsteps;
    int pos, hue;
    int posdir, huedir;

    numsteps = random (500) + 50;
    pos      = random (NUMLEDS);
    hue      = random (360);
    hsb2rgb (hue, 255, 255, colours);
    strip.setPixelColor (pos, colours [0], colours [1], colours [2]);

    for (int j = 0;   j < numsteps;   j++)
    {
        strip.setPixelColor (pos, 0, 0, 0);
        posdir = random (2);
        huedir = random (2);
        if (posdir == 0)
            pos++;
        else
            pos--;
        if (pos >= NUMLEDS) pos = 0;
        if (pos < 0)        pos = NUMLEDS - 1;
        if (huedir == 0)
            hue += DELTAHUE;
        else
            hue -= DELTAHUE;
        if (hue >= 360) hue =   0;
        if (hue < 0)    hue = 359;
        hsb2rgb (hue, 255, 255, colours);
        strip.setPixelColor (pos, colours [0], colours [1], colours [2]);
        strip.show ();
        delay (DELAYRANDOMWALK);
    }
    strip.setPixelColor (pos, 0, 0, 0);
}
