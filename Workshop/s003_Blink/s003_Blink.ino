/*
 *  Blink
 *  zwei LEDs unabhaengig blinlken lassen
 *
 *  2015-11-05   Daniel LeMath    erzeugt
 *
 **********************************************************************/

// Die Pins, an denen die LEDS angeschlossen sind
const byte LEDPIN1   = 3;
const byte LEDPIN2   = 4;

// Die Delays für die beiden LEDS
const int DELAY1 = 500;
const int DELAY2 = 350;

// Startwerte für die Zeitbestimmung
long old_millis1 = 0;
long old_millis2 = 0;

// Die Anfangsstatus der beiden LEDs
byte ledstate1 = LOW;
byte ledstate2 = LOW;

/* ******************** setup ********************  */
void setup ()
{
    // Setze die Pins auf Ausgabe
    pinMode (LEDPIN1, OUTPUT);
    pinMode (LEDPIN2, OUTPUT);
}

/* ******************** loop  ********************  */
void loop ()
{
    // die aktuelle Zeit bestimmen
    long milli = millis ();

    // wenn die Differenz zur gemerkten Zeit groesser als DELAY1,
    // dann die Zeit speichern und LED 1 umschalten
    if (milli - old_millis1 > DELAY1)
    {
        old_millis1 = milli;
        ledstate1 = ! ledstate1;
        digitalWrite (LEDPIN1, ledstate1);
    }

    // wenn die Differenz zur gemerkten Zeit groesser als DELAY2,
    // dann die Zeit speichern und LED 2 umschalten
    if (milli - old_millis2 > DELAY2)
    {
        old_millis2 = milli;
        ledstate2 = ! ledstate2;
        digitalWrite (LEDPIN2, ledstate2);
    }
}   // Ende loop

