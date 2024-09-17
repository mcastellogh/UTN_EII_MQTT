/*********************************************************************************
 * 
 *                       ELECTRONICA II UTN - FRRO                                *
 * 
 * *******************************************************************************/

//===================[File header]================================================
// File:                app.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Licence:             GPLV3+
// Version:             1.0.0
// Date:                Julio 2024
// Info:                Project 'MQTT' for Electrónica II

//====================[Use & storage]============================================
// PCB:                 NodeMCU 
// Plataforma:          ESP32 
// Use:                 mqtt
// Folder:              mqtt
// Proyect name:        mqtt

//====================[ToDo]=====================================================     
//        
//
//
//====================[Bugs]=====================================================     
//     
//                   
//
//====================[Commits]==================================================     
//
// Last commit:
//
//===================[End file header]===========================================

//--Includes
#include "app.h"

//--Local variables
bool mqtt_state=0;
extern bool wifi_state;

//--Main application
void App_loop(void){
    wifi_state=wifi_loop();
    mqtt_state=broker_loop();
}