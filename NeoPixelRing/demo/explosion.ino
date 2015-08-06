/*  explosion
 *
 *  2014-07-12   Andreas Dunker   created
 *
 *  TODO: has to be revised
 *
 **********************************************************************/

#define DELAYEXPLOSION 100

void explosion ()
{
    int numexp = random (10) + 5;
    int colours [3];

    for (int i = 0;   i < numexp;   i++)
    {
//        Serial.print ("    explosion: round "); Serial.print (i); Serial.print ("/"); Serial.println (numexp);
/*
 *      1. two pixels upwards
 *      =====================
 */
        hsb2rgb (random (360), 255, 255, colours);
        for (int j = 0;   j < NUMLEDS / 2;   j++)
        {
            if (j > 0)
            {
                strip.setPixelColor (j - 1, 0, 0, 0);
                strip.setPixelColor (NUMLEDS - j, 0, 0, 0);
            }
            strip.setPixelColor (j, colours [0], colours [1], colours [2]);
            strip.setPixelColor (NUMLEDS - j - 1, colours [0], colours [1], colours [2]);
            strip.show ();
            delay (DELAYEXPLOSION);
        }
/*
 *      2. fill from top
 *      ================
 */
        hsb2rgb (random (360), 255, 255, colours);
        for (int j = (NUMLEDS / 2) - 1;   j >= 0;   j--)
        {
            for (int k = 0;   k < 255;   k++)
            {
                float factor = float (k) / float (255);
                strip.setPixelColor (j, colours [0] * factor, colours [1] * factor, colours [2] * factor);
                strip.setPixelColor (NUMLEDS - j - 1, colours [0] * factor, colours [1] * factor, colours [2] * factor);
                strip.show ();
//                delay (1);
//                delay (DELAYEXPLOSION);
            }
        }
/*
 *      3. clear from bottom
 *      ====================
 */
        for (int j = 0;   j < NUMLEDS / 2;   j++)
        {
            for (int k = 254;   k >= 0;   k--)
            {
                float factor = float (k) / float (255);
                strip.setPixelColor (j, colours [0] * factor, colours [1] * factor, colours [2] * factor);
                strip.setPixelColor (NUMLEDS - j - 1, colours [0] * factor, colours [1] * factor, colours [2] * factor);
                strip.show ();
//                delay (1);
            }
        }
        
        strip.show ();
        delay (DELAYEXPLOSION);
        for (int j = 0;   j < NUMLEDS;   j++)
        {
            strip.setPixelColor (j, 0, 0, 0);
        }
    }
}
