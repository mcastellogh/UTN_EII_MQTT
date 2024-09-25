#ifndef _commands_h_
#define _commands_h_

#include <Arduino.h>
#include <ArduinoJson.h>


void rpc_proc(char* topic, byte* payload, unsigned int length);

#endif