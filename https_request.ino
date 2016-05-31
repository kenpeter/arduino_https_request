#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClientSecure.h>
#include <WiFiClient.h>

#include "device.h"


extern "C" {
// need to include this SDK header as we need to call some of the SDK directly
#include "user_interface.h"
}


// NOTE: if I comment this out, it will work
ESP8266WebServer g_web_server(80);

void setup() {
  //test
  get_device_info();
}

void loop() {
}
