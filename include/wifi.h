#ifndef _wifi_h_
#define _wifi_h_

//--Includes
#include <Arduino.h>
//#include <WiFi.h>
#include <WiFiClientSecure.h>
#include "config.h"
#include "leds.h"
#include "setup.h"

#define RECONN_TIMEOUT              20000     //Timeout to wait reconnection
#define WAITFORCONNECT_TIMEOUT      20000     //Timeout to wait connection

enum FSM_WIFI_STATES {
    WIFI_DISCONNECTED,
    WIFI_CONNECTED,
    WIFI_RECONNECT,
    WIFI_WAITTORECONNECT,
    WIFI_WAITFORCONNECT
};

//--Prototypes
bool wifi_init(WiFiMode_t mode);
bool wifi_loop(void);

//--Privates prototypes
bool _connect(void);
void _FSM_state_led(uint8_t _wifi_state, uint8_t led);
uint8_t _get_wifi_status(void);
void _APconnect(void);

#endif