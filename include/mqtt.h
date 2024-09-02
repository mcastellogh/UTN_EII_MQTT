#ifndef _mqtt_h_
#define _mqtt_h_

#include <Arduino.h>
#include <PubSubClient.h>
#include <LittleFS.h>
#include "setup.h"
#include "wifi.h"
#include "cert.h"


/*======================================[macros y definiciones]============================================*/
#define RECONN_MQTT_TIMEOUT              20000      //Timeout para espera de reconexion (ventana para atender web server)
#define WAITFORCONNECT_MQTT_TIMEOUT      20000      //Timeout para espera de conexion
#define DELAY_PUB_MQTT_LED               20         //Delay para indicador de publicacion
#define MAX_RECONN                       15

enum FSM_MQTT_STATES {
    _MQTT_DISCONNECTED,
    _MQTT_CONNECTED,
    _MQTT_RECONNECT,
    _MQTT_WAITTORECONNECT,
    _MQTT_WAITFORCONNECT,
    _MQTT_UNAVAILABLE_CONNECTION
};


void broker_init(void);//const char * server, uint16_t port_server, const char * device, const char * topic_att, const char * topic_rpc, int led, std::function<void (char *, uint8_t *, unsigned int)> callb);
bool broker_conn(void);
bool broker_loop(void);
bool broker_pub(const char* topic, const char* message); 
uint8_t broker_get_mqtt_status(void);
void broker_FSM_blink_led(uint8_t __mqtt_state);
bool broker_sub(const char*topic);
void rpc_proc(char* topic, byte* payload, unsigned int length);


#endif