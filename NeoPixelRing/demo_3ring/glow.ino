/*  glow - glow all LEDs
 *
 *  2015-07-10   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYGLOW 20

byte numglows = random (10) + 5;

void glow ()
{
    int colours [3];
    for (byte j = 0;   j < numglows;   j++)
    {
        int col = random (360);
        for (int val = 0;   val < 255;   val++)
        {
            hsb2rgb (col, 255, val, colours);
            for (int led = 0;   led < NUMLEDS;   led++)
            {
                strip.setPixelColor (led, colours [0], colours [1], colours [2]);
            }
            strip.show ();
            delay (DELAYGLOW);
        }
        for (int val = 254;   val >= 0;   val--)
        {
            hsb2rgb (col, 255, val, colours);
            for (int led = 0;   led < NUMLEDS;   led++)
            {
                strip.setPixelColor (led, colours [0], colours [1], colours [2]);
            }
            strip.show ();
            delay (DELAYGLOW);
        }
    }
}

