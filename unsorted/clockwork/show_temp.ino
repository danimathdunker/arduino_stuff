/*  show_temp - shows temperature
 *
 *  2016-06-22   Andreas Dunker   created
 *
 ************************************************************************/

void show_temp ()
{
    int  temp_h      = 0;
    int  temp_l      = 0;
    int  temperature = int (fTemperature + 0.5);
    int colours [3];

    Serial.print (fTemperature); Serial.println (" °");
    
	temp_h = temperature / 10;
    temp_l = temperature - ((temperature / 10) * 10);

    if (temperature < 15)
    {
    	colour_temp = 180;
    }
    else if (temperature < 18)
    {
    	colour_temp = 240;
    }
    else if (temperature < 20)
    {
    	colour_temp = 140;
    }
    else if (temperature < 22)
    {
    	colour_temp = 120;
    }
    else if (temperature < 25)
    {
    	colour_temp = 50;
    }
    else
    {
    	colour_temp = 0;
    }

    hsb2rgb (colour_temp, 255, 255, colours);
    rgbDigit.setDigit (temp_h, 0, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit (temp_l, 1, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit (' ', 2, colours [0], colours [1], colours [2]);
    rgbDigit.setDigit ('*', 3, colours [0], colours [1], colours [2]);
}

