/*  redgreen - christmasish
 *
 *  2014-12-13   Andreas Dunker   created
 *
 **********************************************************************/

#define DELAYRG 200

void redgreen ()
{
     int numloops = random (50) + 5;
     for (int n = 0;   n < numloops;   n++)
     {
         for (int l = 0;   l < NUMLEDS;   l++)
         {
             if ((l % 2) == 0)
             {
                 strip.setPixelColor (l, 255, 0, 0);
             }
             else
             {
                 strip.setPixelColor (l, 0, 255, 0);
             }
         }
         strip.show ();
         delay (DELAYRG);
         for (int l = 0;   l < NUMLEDS;   l++)
         {
             if ((l % 2) == 1)
             {
                 strip.setPixelColor (l, 255, 0, 0);
             }
             else
             {
                 strip.setPixelColor (l, 0, 255, 0);
             }
         }
         strip.show ();
         delay (DELAYRG);
    }
    for (int l = 0;   l < NUMLEDS;   l++)
    {
        strip.setPixelColor (l, 0, 0, 0);
    }
}
