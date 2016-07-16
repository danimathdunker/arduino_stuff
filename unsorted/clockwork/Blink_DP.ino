void Blink_DP ()
{
	Serial.print ("DP 1: "); Serial.println (Run_blink);
    if (Run_blink == 0)
    {
//        rgbDigit.showDot (1, random (100), random (100), random (100));      // set DP on
        rgbDigit.showDot (1, 127, 127, 127);      // set DP on
        Run_blink = 1;
    }
    else
    {
        rgbDigit.showDot (1, 0, 0, 0);               // turn of DP
        Run_blink = 0;
    }
}
