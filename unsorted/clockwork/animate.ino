/*  animate - some blinking lights
 *
 *  2016-06-23   Andreas Dunker   created
 *
 ************************************************************************/

const byte NUM_ANIS = 1;

void animate ()
{
	byte ani = random (NUM_ANIS);

    switch (ani)
    {
    	case 0:
    	    colour_wheel();
    	    break;
    }
}

void colour_wheel ()
{
	int colours [3];

    for (byte k = 0;   k < random (10);   k++)
    {
        for (int j = 0;   j < 360;   j++)
	    {
		    hsb2rgb (j, 255, 255, colours);
		    rgbDigit.setDigit (8, 0, colours [0], colours [1], colours [2]);
		    rgbDigit.setDigit (8, 1, colours [0], colours [1], colours [2]);
		    rgbDigit.setDigit (8, 2, colours [0], colours [1], colours [2]);
		    rgbDigit.setDigit (8, 3, colours [0], colours [1], colours [2]);
	    }
    }
}


