/*  inout2 - from inner ring to outer ring, another pattern
 *
 *  2015-09-20   Andreas Dunker   created
 *
 **********************************************************************/

const int INOUT2DELAY = 250;
byte inout2loops = random (10) + 50;

void inout2 ()
{
    uint8_t col_inn [4];
    uint8_t col_mid [4];
    uint8_t col_out [4];
    
    for (byte j = 0;   j < 4;   j++)
    {
        col_inn [j] = 0;
        col_mid [j] = 0;
        col_out [j] = 0;
    }

    for (byte k = 0;   k < inout2loops;   k++)
    {
        for (int led = 0;   led < NUM_OUTER;   led++)
        {
            leds [led].setHue (col_out [4 * led / NUM_OUTER]);
        }
        for (int led = 0;   led < NUM_MIDDL;   led++)
        {
            leds [led + NUM_OUTER].setHue (col_mid [4 * led / NUM_MIDDL]);
        }
        for (int led = 0;   led < NUM_INNER;   led++)
        {
            leds [led + NUM_OUTER + NUM_MIDDL].setHue (col_inn [4 * led / NUM_INNER]);
        }
        FastLED.show ();
        for (int j = 0;   j < 4;   j++)
        {
            col_out [j] = col_mid [j];
            col_mid [j] = col_inn [j];
            col_inn [j] = random (255);
        }
        delay (INOUT2DELAY);
    }
    clearall ();
}
