/*  show_clock - shows clock
 *
 *  2016-06-22   Andreas Dunker   created
 *
 ************************************************************************/

void show_clock ()
{
	byte hour_h = 0;  byte hour_l = 0;
    int  min_h = 0;   int  min_l = 0;
    int colours [3];
    byte dummy;

	Serial.print (hours); Serial.print (":"); Serial.print (minutes); Serial.print (":"); Serial.println (seconds);

	hour_h = hours / 10;
    hour_l = hours - ((hours / 10) * 10);
    min_h  = minutes / 10;
    min_l  = minutes - ((minutes / 10) * 10);

    colour_hour += random (1, 3);;
    if (colour_hour > 359) colour_hour -= 360;
    if (colour_hour <   0) colour_hour += 360;

    colour_minute += random (1, 3);
    if (colour_minute > 359) colour_minute -= 360;
    if (colour_minute <   0) colour_minute += 360;

    hsb2rgb (colour_hour, 255, 255, colours);
    rgbDigit.setDigit (hour_h, 0, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit (hour_l, 1, colours [0], colours [1], colours [2]);

    hsb2rgb (colour_minute, 255, 255, colours);
    rgbDigit.setDigit (min_h, 2, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit (min_l, 3, colours [0], colours [1], colours [2]);
}
