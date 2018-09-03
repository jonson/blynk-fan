#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "Fan.h"
#include "config.h"

// add #defines in config.h for the following
char auth[] = BLYNK_AUTH;
char ssid[] = WIFI_SSID;
char pass[] = WIFI_PASSWORD;

const int TX_PIN = 5;   // NodeMCU pin D1 = GPIO 5

Fan fan(TX_PIN);

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) {
    int pinValue = param.asInt();
    if (pinValue == 1) {
      fan.toggleLight();
    }
}

BLYNK_WRITE(V1) {
    int pinValue = param.asInt();
    if (pinValue == 1) {
      fan.fanOff();
    }
}

BLYNK_WRITE(V2) {
    int pinValue = param.asInt();
    if (pinValue == 1) {
      fan.fanLow();
    }
}

BLYNK_WRITE(V3) {
    int pinValue = param.asInt();
    if (pinValue == 1) {
      fan.fanMedium();
    }
}

BLYNK_WRITE(V4) {
    int pinValue = param.asInt();
    if (pinValue == 1) {
      fan.fanHigh();
    }
}

void loop()
{
  Blynk.run();
}
