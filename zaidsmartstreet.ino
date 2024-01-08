#define BLYNK_TEMPLATE_ID "TMPL61Tdr3pK8"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "h_c4epiueXaq1fySBdTRXmUthZKeIw-E"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Alasad";
char pass[] = "flying773";

int IR_sensor = D6;
int LED = D7;

int ledPin = 13; // D7
int inputPin = 12; // D6
int val = 0;

bool isControlledByBlynk = false;
unsigned long previousMillis = 0;
const long interval = 1000;

BLYNK_WRITE(V0) {
  int state = param.asInt();
  digitalWrite(ledPin, state);
  isControlledByBlynk = (state == HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();

  if (!isControlledByBlynk) {
    val = digitalRead(inputPin);
    if (val == HIGH) {
      digitalWrite(ledPin, LOW);
    } else {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        digitalWrite(ledPin, HIGH);
      }
    }
  }
}