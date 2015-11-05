/*
 *  Taster
 *  Taster schaltet LED ein
 *
 *  2015-11-05   Daniel LeMath    erzeugt
 *
 **********************************************************************/

const byte LEDPIN   = 3;
const byte INPUTPIN = 2;

void setup ()
{
    pinMode (LEDPIN, OUTPUT);
    pinMode (INPUTPIN, INPUT);
}

void loop ()
{
    byte wert = digitalRead (INPUTPIN);
    if (wert == LOW)
    {
        digitalWrite (LEDPIN, HIGH);
    }
    else
    {
        digitalWrite (LEDPIN, LOW);
    }
}

