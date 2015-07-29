/*  Spider - sketch for spider control
 *
 *  12. Apr 2012   Andreas   created
 *
 **********************************************************************/
byte          usPin = 8;            // ultrasound pin
unsigned long usDuration;           // ultrasound duration
unsigned int  cm;                   // roughly calculated cm
byte          ledPin = 3;           // LED pin
int           brightness;           // LED brightness
int           min_threshold =  15 ; // treshold for bkinking LED
const int     max_threshold = 75;   // treshold for brightning LED
const int     mesDelay = 200;       // msec between measurments
int           old_event_time;       // time of last event
const int     delta_events = 20000; // msec between events

//#define DEBUG

/*   setup - initialise things
 *
 **********************************************************************/
void setup ()
{
#ifdef DEBUG
    Serial.begin (9600);
#endif
    old_event_time = millis ();
    analogWrite (ledPin, 255);
    usDuration = getDist ();  // warm up measurement
    delay (2500);
    analogWrite (ledPin, 0);
}

/*   loop - the ever lasting loop
 *
 **********************************************************************/

void loop ()
{
#ifdef EVENT
    if (abs (millis () - old_event_time) > delta_events)
    {
        analogWrite (ledPin, 127);
        delay (500);
        analogWrite (ledPin, 255);
        delay (500);
        analogWrite (ledPin, 0);
        old_event_time = millis ();
    }
#endif
    usDuration = getDist ();
    cm = usDuration / 58;  // int is enough for this
#ifdef DEBUG
    Serial.print   ("usDuration: "); Serial.println (usDuration);
#endif
    if (cm < min_threshold)
    {
        if (brightness == 0)
            brightness = 255;
        else
            brightness = 00;
    }
    else if (cm < max_threshold)
        brightness = map (cm, 0, max_threshold, 200, 0);
    else
        brightness = 0;
    analogWrite (ledPin, brightness);
    delay (mesDelay);
}

/*   getDist - gets the distance from SRF05
 *
 *   return value: micro seconds
 *
 **********************************************************************/
unsigned long getDist ()
{
    unsigned long retVal;

    pinMode (usPin, OUTPUT);
    digitalWrite (usPin, LOW);
    delayMicroseconds (2);
    digitalWrite (usPin, HIGH);
    delayMicroseconds (10);
    digitalWrite (usPin, HIGH);

    pinMode (usPin, INPUT);
    retVal = pulseIn (usPin, HIGH);
#ifdef DEBUG
    Serial.print (retVal); Serial.print (", "); Serial.print (retVal / 58.0); Serial.println (" cm");
#endif
    return (retVal);
}



