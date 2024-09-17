#ifndef _publish_h_
#define _publish_h_

#include <Arduino.h>
#include <ArduinoJson.h>
#include "mqtt.h"
#include "config.h"
#include "setup.h"


#define PUBLISH_INTERVAL 10000

//--Prototypes
void publish_measures(void);



#endif