/*
 *  Blink
 *  zwei LEDs unabhaengig
 *
 *  2015-11-05   Daniel LeMath    erzeugt
 *
 **********************************************************************/

const byte LEDPIN1   = 3;
const byte LEDPIN2   = 4;

const int DELAY1 = 500;
const int DELAY2 = 350;

long old_millis1 = 0;
long old_millis2 = 0;

byte ledstate1 = LOW;
byte ledstate2 = LOW;

void setup ()
{
    pinMode (LEDPIN1, OUTPUT);
    pinMode (LEDPIN2, OUTPUT);
}

void loop ()
{
    long milli = millis ();
    if (milli - old_millis1 > DELAY1)
    {
        old_millis1 = milli;
        ledstate1 = ! ledstate1;
        digitalWrite (LEDPIN1, ledstate1);
    }

    if (milli - old_millis2 > DELAY2)
    {
        old_millis2 = milli;
        ledstate2 = ! ledstate2;
        digitalWrite (LEDPIN2, ledstate2);
    }
}

