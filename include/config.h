#ifndef _config_h_
#define _config_h_

//--Includes
#include <Arduino.h>

//--Hardware PINS definitions
#define ONBOARD_LED_PIN             2
#define WIFI_LED_PIN                2
#define MQTT_LED_PIN                23


//--Software constants
#define SERIAL_BAUDRATE             19200

//--Structures
struct Config {
  const char* device;
  const char* ssid;
  const char* ssid_pass;
  const char* ap_ssid;
  const char* ap_pass;
  const char* mqtt_server;
  uint16_t mqtt_tcp;
};


#endif