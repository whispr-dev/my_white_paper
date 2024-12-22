#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>

void initHardware();
void setMUXForMode(uint8_t sSel, uint8_t rSel, uint8_t clkSel);
bool readQState();
bool readQBState();
void updateLEDs(bool q, bool qb);
int readUserInput(); // Read encoder or button
#endif
