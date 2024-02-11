// All the toggles are in the "main.hpp" file
#include "main.h"
#include "CAN_Handle.hpp"

// If you want to add a new sensor, create a hpp file with your defs, libs and
// its logic, you'll also have to add the sensor to the CIs class in
// "CAN_Label_Maker.hpp" and define how you want that to generate its IDs

// Get IDs after calcs
CIs ID = calc_IDs(node_fl); // SET OFFSET HERE

// Some globals
Metro uPot = 50;   // Shock Pot pol rate
Metro uSpeed = 50; // Wheel speed pol rate
Metro uTemps = 50; // Tire Temp pol rate
Metro uART = 3000; // Timeout for waiting on user to connect

// Pot fl_pt;
// Wheel_Spd fl_ws;
Tire_Temp fl_tt;

void setup() {
  // Start serial
  Serial.begin(9600);

  // fl_pot.init(1, true, 0);
  // fl_ws.init(9, 0);
  fl_tt.init();

  // Setup whatever CAN coms
  init_CAN();

#ifdef DEBUG
  // Wait for user to connect to see all output
  while (!Serial) {
    // Break on timeout
    if (uART.check()) {
      break;
    }
    delay(10);
  }

  Serial.println("Debug enabled");
#endif
}

void loop() {
  if (uPot.check()) {
    // send_CAN(ID.apotsID, fl_pot.getMessage());
    // fl_pot.getMessage();
  }

  if (uTemps.check()) {
    //   send_CAN(ID.ttempID, fl_tt.getMessage());
    fl_tt.getMessage();
  }

  if (uSpeed.check()) {
    // send_CAN(ID.speedID, fl_ws.getMessage());
    // fl_ws.getMessage();
  }

  // Update our fellows
  // fl_ws.update();
}
