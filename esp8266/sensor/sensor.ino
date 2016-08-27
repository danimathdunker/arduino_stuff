/*  sensor_hum_temp - sensor for humidity and temperature
 *
 *  IMPORTANT: change lines 17 to 22 according to your data
 *
 *  2016-08-27   Andreas Dunker   created
 *
 **********************************************************************/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "Adafruit_HDC1000.h"

ADC_MODE(ADC_VCC);

// comment the next line, if you don't need serial output
#define DEBUG

const char* SSID        = "wifi";
const char* PASSWORD    = "password";
const char* MQTT_SERVER = "aaa.bbb.ccc.ddd";
const char* SENSOR_DESC = "Proto";

const int LED     =   5;
const int MSG_LEN = 256;


const unsigned long SLEEPTIME = 60000000;

const int SDA_PIN =  2;
const int SCL_PIN = 14;

void setup ()
{
/*
 *  1. variables
 *  ============
 *  1.1. WiFi
 *  ---------
 */
    WiFiClient   espClient;
    PubSubClient client (espClient);
    char         msg [MSG_LEN];
    char         topic [MSG_LEN];
/*
 *  1.2. Sensor
 *  -----------
 */
    Adafruit_HDC1000 hdc = Adafruit_HDC1000 ();
    long temperature;
    long humidity;
/*
 *  1.3. stuff
 *  ----------
 */
    int ledstate     = LOW;
    int mqtt_attempt = 0;
    uint16_t voltage;
/*
 *  2. init
 *  =======
 */
    pinMode (LED, OUTPUT);
#ifdef DEBUG
    Serial.begin (115200);
#endif
/*
 *  3. connect to WiFi
 *  ==================
 */
#ifdef DEBUG
    Serial.print ("Connecting to "); Serial.println (SSID);
#endif
    WiFi.begin (SSID, PASSWORD);
    while (WiFi.status () != WL_CONNECTED)
    {
#ifdef DEBUG
        ledstate = ! ledstate;
        digitalWrite (LED, ledstate);
#endif
        delay (500);
    }
    digitalWrite (LED, LOW);
#ifdef DEBUG
    Serial.println ("Connected");
#endif
/*
 *  4. read data
 *  ============
 */
    Wire.begin (SDA_PIN, SCL_PIN);
    if (! hdc.begin ())
    {
#ifdef DEBUG
        Serial.println("Couldn't find sensor!");
        Serial.print ("Perhaps in "); Serial.print (SLEEPTIME); Serial.println (" microseconds");
#endif
        ESP.deepSleep (SLEEPTIME, WAKE_RF_DEFAULT);
    }
    temperature = (long) (hdc.readTemperature() * 100.0);
    humidity    = (long) (hdc.readHumidity() * 100.0);
    voltage     = ESP.getVcc ();
#ifdef DEBUG
    Serial.print (temperature); Serial.print (" deg C, ");
    Serial.print (humidity); Serial.println (" %");
#endif
/*
 *  5. publish data
 *  ===============
 */
    client.setServer (MQTT_SERVER, 1883);
    while (! client.connected ())
    {
        mqtt_attempt++;
#ifdef DEBUG
        digitalWrite (LED, HIGH);
        Serial.print (SENSOR_DESC);
        Serial.print (": Attempting MQTT connection...");
#endif
        if (client.connect (SENSOR_DESC)) // try to connect
        {
#ifdef DEBUG
            Serial.println ("connected");
#endif
            digitalWrite (LED, LOW);
        }
        else
        {
#ifdef DEBUG
            Serial.print ("failed, rc="); Serial.print (client.state());
            Serial.print (", attempt #"); Serial.print (mqtt_attempt);
            Serial.println (" try again in 2 seconds");
#endif
            if (mqtt_attempt >= 25)
            {
#ifdef DEBUG
                Serial.println ("too many tries; goto sleep");
                ESP.deepSleep (SLEEPTIME, WAKE_RF_DEFAULT);
#endif
            }
            delay (2000);
        }
        digitalWrite (LED, LOW);
    }
    snprintf (topic, MSG_LEN, "wohnung/temphum/%s", SENSOR_DESC);
    snprintf (msg, MSG_LEN, "%ld %ld %d %ld", temperature, humidity, mqtt_attempt, voltage);
#ifdef DEBUG
    Serial.println (topic);
    Serial.println (msg);
#endif
    client.loop ();
    client.publish (topic, msg);
/*
 *  6. good night
 *  =============
 */
#ifdef DEBUG
    Serial.print ("Good night for "); Serial.print (SLEEPTIME); Serial.println (" microseconds");
#endif
    ESP.deepSleep (SLEEPTIME, WAKE_RF_DEFAULT);
}

void loop ()
{
    // empty - all the work is done in setup, then a deep sleep
}
