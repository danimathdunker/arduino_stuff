/*  hsb2rgb - change HSB value into RGB
 *
 *  parameters: hue: in    : hue value (0 - 359)
 *              sat:     in: saturation (0 - 255)
 *              val:     in: lightness (0 - 255)
 *              colors: out: array of RGB values
 *              
 *
 *  from: http://log.liminastudio.com/itp/physical-computing/arduino-controlling-an-rgb-led-by-hue
 *
 ************************************************************************/
 */

void hsb2rgb (int hue, int sat, int val, int colors [3])
{
    int r, g, b, base;

    if (sat == 0) { // Achromatic color (gray).
        colors[0]=val;
        colors[1]=val;
        colors[2]=val;
    } else  {
        base = ((255 - sat) * val)>>8;
        switch(hue/60) {
            case 0:
                r = val;
                g = (((val-base)*hue)/60)+base;
                b = base;
                break;
            case 1:
                r = (((val-base)*(60-(hue%60)))/60)+base;
                g = val;
                b = base;
                break;
            case 2:
                r = base;
                g = val;
                b = (((val-base)*(hue%60))/60)+base;
                break;
            case 3:
                r = base;
                g = (((val-base)*(60-(hue%60)))/60)+base;
                b = val;
                break;
            case 4:
                r = (((val-base)*(hue%60))/60)+base;
                g = base;
                b = val;
                break;
            case 5:
                r = val;
                g = base;
                b = (((val-base)*(60-(hue%60)))/60)+base;
                break;
        }
        colors[0]=r;
        colors[1]=g;
        colors[2]=b;
    }
}


