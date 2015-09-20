/*  windmill - nomen est omen
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

// TODO stop this flickering

#define DELAYMILL 50

int col = random (255);

void windmill ()
{
    int  numrounds = random (30) + 10;
    byte ledpos_out, ledpos_mid, ledpos_inn;

    for (int rounds = 0;   rounds < numrounds;   rounds++)
    {
        for (byte start = 0;   start < NUM_OUTER / 2;   start++)
        {
           if (++col > 255) col = 0;
            for (byte pos = 0;   pos < NUM_OUTER / 4;   pos++)
            {
                for (byte j = 0;   j < 2;   j++)
                {
                    ledpos_out = start + pos + j * NUM_OUTER / 2;
                    if (ledpos_out >= NUM_OUTER) ledpos_out -= NUM_OUTER;
                    leds [ledpos_out] = CHSV (col, 255, 255);

                    ledpos_mid = NUM_OUTER + ledpos_out * NUM_MIDDL / NUM_OUTER;
                    if (ledpos_mid >= NUM_OUTER + NUM_MIDDL) ledpos_mid = ledpos_mid - (NUM_OUTER + NUM_MIDDL);
                    leds [ledpos_mid] = CHSV (col, 255, 255);

                    ledpos_inn = NUM_OUTER + NUM_MIDDL + ledpos_out * NUM_INNER / NUM_OUTER;
                    if (ledpos_inn >= NUM_OUTER + NUM_MIDDL + NUM_INNER)
                        ledpos_inn = ledpos_inn - (NUM_OUTER + NUM_MIDDL + NUM_INNER);
                    leds [ledpos_inn] = CHSV (col, 255, 255);
                }
            }
            FastLED.show ();
            delay (DELAYMILL);

            clearall ();
        }
    }   // end for rounds
}

