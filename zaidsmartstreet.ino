#define BLYNK_TEMPLATE_ID "TMPL61Tdr3pK8"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "h_c4epiueXaq1fySBdTRXmUthZKeIw-E"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "h_c4epiueXaq1fySBdTRXmUthZKeIw-E";
char ssid[] = "Alasad";
char pass[] = "flying773";

int IR_sensor = D6;
int LED = D7;


int ledPin = 13; // D7 choose pin for the LED
int inputPin =12; // D6 choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status

BLYNK_WRITE(V0) {
  digitalWrite(D7, param.asInt());
}

void setup() 
{  
  
  Serial.begin(9600);
   pinMode(ledPin, OUTPUT); // declare LED as output 
   pinMode(inputPin, INPUT); // declare Infrared sensor as input

   /////now the blink light
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}


void loop() {

  Blynk.run();
  // put your main code here, to run repeatedly:
   val = digitalRead(inputPin); // read input value 
   if (val == HIGH)
   { // check if the input is HIGH
      digitalWrite(ledPin, LOW); // turn LED OFF 
      Serial.print(val);
      Serial.println("IR Sensor Value with out Object in front of the Sensor");
 
   } 
   else 
   { 
      digitalWrite(ledPin, HIGH); // turn LED ON 
      Serial.print(val);
      Serial.println("IR Sensor Value with an Object in front of the Sensor");
      delay(5000);
   } 
   
  
}
