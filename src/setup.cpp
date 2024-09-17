//=======================================================================
// File:                setup.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Julio 2024
// Info:                Project for Electrónica II
//=======================================================================

//--Includes
#include "setup.h"

//--Local variables
uint8_t var_count;
Config config;
bool wifi_state=0;

//--Global variables
const char * topic_telemetry      =   "v1/devices/me/telemetry";
const char * topic_attributes     =   "v1/devices/me/attributes";
const char * topic_rpc            =   "v1/devices/me/rpc/request/+";

//--Extern variables




//--Startup function
void App_setup(void){
    Serial.begin(SERIAL_BAUDRATE);

    //--PINS
    pinMode(ONBOARD_LED_PIN,OUTPUT);
    pinMode(WIFI_LED_PIN,OUTPUT);

    led_welcome();

    //--Init configs
    config.device="nivciscem01";
    config.ssid="MAC_E";
    config.ssid_pass="wpaadministrator08";
    config.ap_ssid=config.device;
    config.ap_pass="12345678";
    config.mqtt_server="192.168.1.25";
    config.mqtt_tcp=8883;

    //--WiFi initialization
    wifi_state=wifi_init(WIFI_AP_STA);

    //--MQTT initialization
    broker_init();
    if (wifi_state){
        broker_conn();
    }

    //--Presentation
    Serial.println("\r\nCátedra de Electrónica II UTN-FRRO");
    Serial.println("Connection and publish data to MQTT broker");
}