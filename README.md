# blynk-fan

A simple esp8266 ceiling fan controller using Blynk.  This was built using a 315mhz transmitter.

## Setup

Add a `config.h` similar to the following:

```
#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

#define BLYNK_AUTH "your-blynk-auth-token"
#define WIFI_SSID "your-wifi-ssid"
#define WIFI_PASSWORD "your-wifi-password"

#endif // PROJECT_CONFIG_H

```
