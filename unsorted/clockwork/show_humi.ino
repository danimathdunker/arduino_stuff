/*  show_humi - shows humidity
 *
 *  2016-06-22   Andreas Dunker   created
 *
 ************************************************************************/

void show_humi ()
{
    int  humi_h   = 0;
    int  humi_l   = 0;
    int  humidity = int (fHumidity + 0.5);
    int colours [3];

    Serial.print (fHumidity); Serial.println ("%");
    
	humi_h = humidity / 10;
    humi_l = humidity - ((humidity / 10) * 10);

    colour_humi++;
    if (colour_humi > 359) colour_humi -= 360;
    if (colour_humi <   0) colour_humi += 360;


    hsb2rgb (colour_humi, 255, 255, colours);
    rgbDigit.setDigit (humi_h, 0, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit (humi_l, 1, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit (' ', 2, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit (' ', 3, colours [0], colours [1], colours [2]);
    rgbDigit.segmentOn(3, 5, colours [0], colours [1], colours [2]);
    rgbDigit.segmentOn(3, 2, colours [0], colours [1], colours [2]);
}

