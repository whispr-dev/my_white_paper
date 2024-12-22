#include "modes.h"
#include "hardware.h"
#include "ui.h"

// Example modes: In reality you would adjust muxSelect lines according to actual wiring
// This is just illustrative:
FlipFlopMode flipFlopModes[] = {
  {"SR Latch", 0x00, 0x00, 0x00, drawSRMode},
  {"D Latch",  0x01, 0x02, 0x00, drawDMode},
  {"JK Flip-Flop", 0x03, 0x04, 0x00, drawJKMode},
  {"T Flip-Flop", 0x05, 0x06, 0x00, drawTMode}
};

const int NUM_MODES = sizeof(flipFlopModes) / sizeof(FlipFlopMode);

void setMode(int modeIndex) {
  if (modeIndex < 0 || modeIndex >= NUM_MODES) return;

  // Set the mux lines according to the mode
  setMUXForMode(flipFlopModes[modeIndex].muxSelectS, flipFlopModes[modeIndex].muxSelectR, flipFlopModes[modeIndex].muxSelectClock);

  // Update the UI
  clearUI();
  drawTitle(flipFlopModes[modeIndex].name);
  flipFlopModes[modeIndex].drawFunc();
}
