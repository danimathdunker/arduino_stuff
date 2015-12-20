/*  windmill - nomen est omen
 *
 *  2015-06-13   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYMILL 50

int col = random (360);

void windmill ()
{
    int  numrounds = random (20) + 10;
    int  colours [3];
    byte ledpos_out, ledpos_mid, ledpos_inn;

    for (int rounds = 0;   rounds < numrounds;   rounds++)
    {
        for (byte start = 0;   start < NUMOUTER / 2;   start++)
        {
           // col += random (10) + 10;
           if (++col > 360) col = 0;
           hsb2rgb (col, 255, 255, colours);
            for (byte pos = 0;   pos < NUMOUTER / 4;   pos++)
            {
                for (byte j = 0;   j < 2;   j++)
                {
                    ledpos_out = start + pos + j * NUMOUTER / 2;
                    if (ledpos_out >= NUMOUTER) ledpos_out -= NUMOUTER;
                    strip.setPixelColor (ledpos_out, colours [0], colours [1], colours [2]);

                    ledpos_mid = NUMOUTER + ledpos_out * NUMMIDDL / NUMOUTER;
                    if (ledpos_mid >= NUMOUTER + NUMMIDDL) ledpos_mid = ledpos_mid - (NUMOUTER + NUMMIDDL);
                    strip.setPixelColor (ledpos_mid, colours [0], colours [1], colours [2]);

                    ledpos_inn = NUMOUTER + NUMMIDDL + ledpos_out * NUMINNER / NUMOUTER;
                    if (ledpos_inn >= NUMOUTER + NUMMIDDL + NUMINNER)
                        ledpos_inn = ledpos_inn - (NUMOUTER + NUMMIDDL + NUMINNER);
                    strip.setPixelColor (ledpos_inn, colours [0], colours [1], colours [2]);
                }
            }
            strip.show ();
            delay (DELAYMILL);

            for (byte pos = 0;   pos < NUMLEDS;   pos++)
            {
                strip.setPixelColor (pos, 0, 0, 0);
            }
            strip.show ();
        }
    }   // end for rounds
}
