/*
 *  esp8266sleep - test for deep sleep mode
 *
 *  2016-08-26   Andreas Dunker   created
 *
 ************************************************************************/

#include <ESP8266WiFi.h>

const int led = 5;
int ledstate  = LOW;
unsigned long last = 0;
/*
 *  setup
 *  =====
 *  the usual setup function
 */
void setup ()
{
    pinMode(led, OUTPUT);
    Serial.begin (115200);
    Serial.println ("Start setup");
    for (byte j = 0;   j < 5;   j++)
    {
        digitalWrite (led, ledstate);
        delay (250);
        ledstate = ! ledstate;
    }
    Serial.println ("End setup");
}

/*
 *  loop
 *  ====
 *  run 10 seconds, then go sleeping
 */

void loop ()
{
    unsigned long now = millis ();
    if ((now - last) > 10000)
    {
        ESP.deepSleep(5000000, WAKE_RF_DEFAULT);
        last = now;
    }
    else
    {
        Serial.print ("loop: "); Serial.print (now); Serial.print (" "); Serial.println (now - last);
        ledstate = ! ledstate;
        digitalWrite (led, ledstate);
    }
    delay (500);
}

