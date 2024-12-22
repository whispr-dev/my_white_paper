#include <Arduino.h>
#include "modes.h"
#include "ui.h"
#include "hardware.h"
#include "ota.h"

// Global variables
int currentModeIndex = 0;
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(115200);
  initHardware();
  initUI();
  initOTA();

  // Set default mode
  setMode(currentModeIndex);
}

void loop() {
  // Handle OTA updates
  handleOTA();

  // Periodic tasks
  unsigned long now = millis();
  if (now - lastUpdate > 100) {
    lastUpdate = now;
    // Update UI and Q states periodically
    bool qState = readQState();
    bool qbState = readQBState();

    updateLEDs(qState, qbState);
    updateUIStateIndicators(qState, qbState);

    // Check for user input (buttons/encoder) to change modes
    int userInput = readUserInput(); // e.g. -1,0,+1 from encoder or button
    if (userInput != 0) {
      currentModeIndex += userInput;
      if (currentModeIndex < 0) currentModeIndex = NUM_MODES - 1;
      if (currentModeIndex >= NUM_MODES) currentModeIndex = 0;
      setMode(currentModeIndex);
    }
  }
}
