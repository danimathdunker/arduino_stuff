/*
 *  Blink
 *  zwei LEDs abwechselnd
 *
 *  2015-11-05   Daniel LeMath    erzeugt
 *
 **********************************************************************/

const int LEDPIN    =    3;
const int ONDELAY   = 1000;
const int OFFDELAY  = 1000;

void setup ()
{
    pinMode (LEDPIN, OUTPUT);
}

void loop ()
{
    digitalWrite (LEDPIN, HIGH);
    delay (ONDELAY);
    digitalWrite (LEDPIN, LOW);
    delay (OFFDELAY);
}
