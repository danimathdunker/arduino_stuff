void Blink_DP ()
{
//        strip.setPixelColor (15, random (100), random (100), random (100));      // set DP on
//        strip.setPixelColor (31, random (100), random (100), random (100));      // set DP on
    if (Run_blink == 0)
    {
        strip.setPixelColor (15, random (100), random (100), random (100));      // set DP on
        strip.setPixelColor (31, random (100), random (100), random (100));      // set DP on
        Run_blink = 1;
    }
    else
    {
        strip.setPixelColor (15, 0, 0, 0);               // turn of DP
        strip.setPixelColor (31, 0, 0, 0);               // turn of DP
        Run_blink = 0;
    }
    strip.show();
}
