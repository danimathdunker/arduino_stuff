/*
 *  esp8266mqtt - sends messages to an MQTT server
 *                Based on the original pubsubclient example.
 *  IMPORTANT: replace WiFi credentials in lines 33 - 35!
 *
 *  ---- cite begin ----
 *  It connects to an MQTT server then:
 *    - publishes "hello world" to the topic "outTopic" every two seconds
 *    - subscribes to the topic "inTopic", printing out any messages
 *      it receives. NB - it assumes the received payloads are strings not binary
 *    - If the first character of the topic "inTopic" is an 1, switch ON the ESP Led,
 *      else switch it off

 *  It will reconnect to the server if the connection is lost using a blocking
 *  reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
 *  achieve the same result without blocking the main loop.

 *  To install the ESP8266 board, (using Arduino 1.6.4+):
 *    - Add the following 3rd party board manager under
 *         "File -> Preferences -> Additional Boards Manager URLs":
 *         http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *    - Open the "Tools -> Board -> Board Manager" and click install for the ESP8266"
 *    - Select your ESP8266 in "Tools -> Board"
 *  ---- cite end ----
 *
 *  2016-08-24   Andreas Dunker   created
 *
 ************************************************************************/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SSID";
const char* password = "password";
const char* mqtt_server = "aaa.bbb.ccc.ddd";

WiFiClient   espClient;
PubSubClient client(espClient);
unsigned long lastMsg = -100000; // millis of last message
char msg [256];
int count_value = 0;  // counter for sent messages

const int led = 5;
int ledstate  = LOW;
/*
 *  setup_wifi
 *  ==========
 *  connects to WiFi
 */
void setup_wifi ()
{
    delay(10);
/*
 *  connecting to a WiFi network
 *  ----------------------------
 */
    Serial.println ();
    Serial.print ("Connecting to ");
    Serial.println (ssid);

    WiFi.begin (ssid, password);
/*
 *  loop until connected
 *  --------------------
 *  toggles LED in every loop
 */
    while (WiFi.status () != WL_CONNECTED)
    {
        ledstate = ! ledstate;
        digitalWrite (led, ledstate);	  
        delay (500);
        Serial.print (".");
    }

    Serial.println ("");
    Serial.println ("WiFi connected");
    Serial.println ("IP address: ");
    Serial.println (WiFi.localIP ());
    digitalWrite (led, LOW);	  
}

/*
 *  reconnect
 *  =========
 *  connects to MQTT server, if not connected
 */
void reconnect ()
{
    // Loop until we're reconnected
    while (!client.connected())
    {
        digitalWrite (led, HIGH);
        Serial.print ("Attempting MQTT connection...");
        if (client.connect("ESP8266Client")) // try to connect
        {
            Serial.println ("connected");
            // Once connected, publish an announcement...
            client.publish ("out/Reconn", "hello world");
        }
        else
        {
            Serial.print ("failed, rc=");
            Serial.print (client.state());
            Serial.println (" try again in 5 seconds");
            delay(5000);
        }
        digitalWrite (led, LOW);
    }
}

/*
 *  setup
 *  =====
 *  the usual setup function
 */
void setup ()
{
    delay (2000);  // wait to be able to start serial console
    pinMode (led, OUTPUT);
    Serial.begin (115200);
    Serial.println ("######################"); Serial.println ("Starting esp8266mqtt");
    setup_wifi ();
    client.setServer (mqtt_server, 1883);
}

/*
 *  loop
 *  ====
 *  run! Forever!
 */

void loop ()
{
/*
 *  if not connected to MQTT server, then connect
 *  ---------------------------------------------
 */
    if (!client.connected ())
    {
        reconnect ();
    }
    client.loop();
/*
 *  if last message more than a minute ago, send another message
 *  ------------------------------------------------------------
 */
    unsigned long now = millis();
    if (now - lastMsg > 60000)
    {
        Serial.print ("lastMsg = "); Serial.print (lastMsg);
        Serial.print (", now = "); Serial.print (now);
        Serial.println ();
        lastMsg = now;
        ++count_value;
        snprintf (msg, 75, "Sensor #0 loop #%ld, time since start: %ld msec", count_value, millis ());
        Serial.print("Publish message: ");
        Serial.println(msg);
        client.publish("out/Topic", msg);
        ledstate = ! ledstate;
        digitalWrite (led, ledstate);
    }
}

