/*
 *  Photowiderstand
 *
 *  2015-11-05   Daniel LeMath    erzeugt
 *
 **********************************************************************/

const byte INPUTPIN = 0;

void setup ()
{
    Serial.begin (9600);
}

void loop ()
{
    int wert = analogRead (INPUTPIN);
    Serial.println (wert);
    delay (1000);
}

