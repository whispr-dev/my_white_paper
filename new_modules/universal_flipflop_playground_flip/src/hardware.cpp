#include "hardware.h"

// Example pin definitions (adjust to your wiring)
#define MUX_S_A0 2
#define MUX_S_A1 4
#define MUX_S_A2 5

#define MUX_R_A0 12
#define MUX_R_A1 13
#define MUX_R_A2 14

#define Q_PIN 25
#define QB_PIN 26

#define LED_Q_PIN 27
#define LED_QB_PIN 33

#define BUTTON_PIN 34

void initHardware() {
  pinMode(MUX_S_A0, OUTPUT);
  pinMode(MUX_S_A1, OUTPUT);
  pinMode(MUX_S_A2, OUTPUT);

  pinMode(MUX_R_A0, OUTPUT);
  pinMode(MUX_R_A1, OUTPUT);
  pinMode(MUX_R_A2, OUTPUT);

  pinMode(Q_PIN, INPUT);
  pinMode(QB_PIN, INPUT);

  pinMode(LED_Q_PIN, OUTPUT);
  pinMode(LED_QB_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void setMUXForMode(uint8_t sSel, uint8_t rSel, uint8_t clkSel) {
  // Example: Assuming 3-bit select lines
  digitalWrite(MUX_S_A0, (sSel & 0x01));
  digitalWrite(MUX_S_A1, (sSel & 0x02));
  digitalWrite(MUX_S_A2, (sSel & 0x04));

  digitalWrite(MUX_R_A0, (rSel & 0x01));
  digitalWrite(MUX_R_A1, (rSel & 0x02));
  digitalWrite(MUX_R_A2, (rSel & 0x04));

  // If you have a clock MUX, set it similarly
  // (Not shown here as no pins defined)
}

bool readQState() {
  return digitalRead(Q_PIN) == HIGH;
}

bool readQBState() {
  return digitalRead(QB_PIN) == HIGH;
}

void updateLEDs(bool q, bool qb) {
  digitalWrite(LED_Q_PIN, q ? HIGH : LOW);
  digitalWrite(LED_QB_PIN, qb ? HIGH : LOW);
}

int readUserInput() {
  // Simple example: pressing a button cycles mode forward
  // Return +1 if button pressed
  static int lastState = HIGH;
  int currentState = digitalRead(BUTTON_PIN);
  if (currentState == LOW && lastState == HIGH) {
    lastState = LOW;
    return +1;
  } else if (currentState == HIGH && lastState == LOW) {
    lastState = HIGH;
  }
  return 0;
}
