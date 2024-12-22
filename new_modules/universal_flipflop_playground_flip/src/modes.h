#ifndef MODES_H
#define MODES_H

#include <Arduino.h>

// Forward declaration of draw functions
void drawSRMode();
void drawDMode();
void drawJKMode();
void drawTMode();
// Add more if needed

typedef struct {
  const char* name;
  uint8_t muxSelectS;      // Example: 3-bit value for S-line MUX select
  uint8_t muxSelectR;      // Example: 3-bit value for R-line MUX select
  uint8_t muxSelectClock;  // If needed for clock lines
  void (*drawFunc)();
} FlipFlopMode;

extern FlipFlopMode flipFlopModes[];
extern const int NUM_MODES;

void setMode(int modeIndex);

#endif
