#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
char auth[] = "gyFYeygYpetXZhg9MGUFgTB-GK_KCPjO";
char ssid[] = "Rafi";
char pass[] = "87654321";

#define trigPIN 14 // NODEMCU TRIGGERPIN D5 > 14
#define echoPIN 12 // NODEMCU ECHOPIN    D6 > 12

void setup()
{
    // Debug console
    Serial.begin(9600);
    pinMode(trigPIN, OUTPUT);
    pinMode(echoPIN, INPUT);
    Blynk.begin(auth, ssid, pass);
}

void loop()
{
    long duration,distance;
    digitalWrite(trigPIN, LOW);
    delayMicroseconds(5);

    digitalWrite(trigPIN, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPIN, LOW);

    duration = pulseIn(echoPIN, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Distance = ");
    Serial.println(distance);
  
    if(distance == 30)
    {
        Blynk.virtualWrite(V1, 255);
        Blynk.email("");
        Blynk.notify("");
    
    }
    else {
        Blynk.virtualWrite(V1, 0);
    }
    Blynk.virtualWrite(V0, distance);
    delay(1000);
    
    Blynk.run();
  
}
