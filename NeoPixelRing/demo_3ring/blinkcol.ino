/*  blinkcol - sparkling stars
 *
 *  Adapted from https://gist.github.com/suhajdab/9716028
 *
 *  2015-12-20   Andreas Dunker   created
 *
 **********************************************************************/

const int BLINKCOLDELAY = 10;

void blinkcol ()
{
    for (uint16_t l = 0; l < NUMLEDS; l++)
    {
        redStates   [l] = 0;
        greenStates [l] = 0;
        blueStates  [l] = 0;
    }
    int numblinks = random (1000) + 1000;
    for (int blinks = 0;   blinks < numblinks;   blinks++)
    {
        if (random (5) == 1)
        {
            uint16_t i = random (NUMLEDS);
            if (redStates [i] < 1 && greenStates [i] < 1 && blueStates [i] < 1)
            {
                redStates   [i] = random (256);
                greenStates [i] = random (256);
                blueStates  [i] = random (256);
            }
        }
    
       for (uint16_t l = 0;   l < NUMLEDS;   l++)
       {
           if (redStates [l] > 1 || greenStates [l] > 1 || blueStates [l] > 1)
           {
               strip.setPixelColor (l, redStates [l], greenStates [l], blueStates [l]);
        
               if (redStates [l] > 1)
               {
                   redStates [l] = redStates [l] * fadeRate;
               }
               else
               {
                   redStates [l] = 0;
               }
        
               if (greenStates [l] > 1)
               {
                   greenStates [l] = greenStates [l] * fadeRate;
               }
               else
               {
                   greenStates [l] = 0;
               }
        
               if (blueStates [l] > 1)
               {
                 blueStates [l] = blueStates [l] * fadeRate;
               }
               else
               {
                   blueStates [l] = 0;
               }
        
           }
           else
           {
               strip.setPixelColor (l, 0, 0, 0);
           }
       }
        strip.show ();
        delay (BLINKCOLDELAY);
    }
}
