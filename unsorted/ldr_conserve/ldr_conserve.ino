/*  ldr_conserve - switch LDR on and off
 *
 *  No current, when D12 is LOW - save energy
 *
 *  GND  ----- LDR -----+----- 10k ----- D12
 *                      |
 *                      |
 *                      A1
 *
 *  2016-07-07   Andreas Dunker   created
 *  
 **********************************************************************/
const byte VPIN = 12;
const byte LDRPIN = A1;

void setup ()
{
    pinMode (VPIN, OUTPUT);
    digitalWrite (VPIN, LOW);
    Serial.begin (115200);
}

void loop ()
{
    int value;
    digitalWrite (VPIN, HIGH);   // VPIN -> 5V: start measurement
    delay (100);                 // let the LDR settle down
    value = analogRead (LDRPIN); // read value
    digitalWrite (VPIN, LOW);    // VPIN -> GND: stop measurement
    Serial.println (value);
    delay (900);
}
