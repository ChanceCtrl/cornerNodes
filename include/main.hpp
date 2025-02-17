#ifndef main_hpp
#define main_hpp

// Arduino stuffs
#include <Arduino.h>
#include <Metro.h>

// Toggles for diffrent features
// #define FLEXCAN // sets CAN provider to the teensy's onboard CAN controller
#define BLUECAN   // sets CAN provider to the MCP2515
#define ANALOGS   // enables reading and sending of pot values
#define WHEEL_SPD // enables reading and sending of wheel speed values
// #define TIRE_TEMP // enables reading and sending of tire temp values
#define DEBUG

// Can stuffs
#include "CAN_Defs.hpp"
#include "CAN_Handle.hpp"

// Pot things
#ifdef ANALOGS
#include "s_Analogs.hpp"
#endif

// Wheel speed things
#ifdef WHEEL_SPD
#include "s_Speed.hpp"
#endif

// Tire temp things
#ifdef TIRE_TEMP
#include "s_Temps.hpp"
#endif

#endif
