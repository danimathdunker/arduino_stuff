/*
 *  Blink
 *  zwei LEDs abwechselnd
 *
 *  2015-11-05   Daniel LeMath    erzeugt
 *
 **********************************************************************/

const int LEDPIN1   =   3;
const int LEDPIN2   =   4;
const int DELAY1    = 500;
const int DELAY2    = 100;

void setup ()
{
    pinMode (LEDPIN1, OUTPUT);
    pinMode (LEDPIN2, OUTPUT);
}

void loop ()
{
    digitalWrite (LEDPIN1, HIGH);
    digitalWrite (LEDPIN2, LOW);
    delay (DELAY1);
    digitalWrite (LEDPIN1, LOW);
    digitalWrite (LEDPIN2, HIGH);
    delay (DELAY1);
}
