/*
 *  Taster
 *  Taster schaltet LED ein
 *
 *  2015-11-05   Daniel LeMath    erzeugt
 *
 **********************************************************************/

const byte LEDPIN   = 3;
const byte INPUTPIN = 2;

byte ledstate = 0;
byte oldval   = 0;

void setup ()
{
    pinMode (LEDPIN, OUTPUT);
    pinMode (INPUTPIN, INPUT);
}

void loop ()
{
    byte wert = digitalRead (INPUTPIN);
    if (wert != oldval)
    {
        if (wert == HIGH)
        {
            Serial.print ("HIGH");
            ledstate = ! ledstate;
            digitalWrite (LEDPIN, ledstate);
        }
        oldval = wert;
    }
}

