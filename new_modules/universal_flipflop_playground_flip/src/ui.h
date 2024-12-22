#include "ui.h"
#include <Wire.h>
// Include your chosen OLED library, e.g.:
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Adjust OLED dimensions and I2C address as needed
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

static Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void initUI() {
  Wire.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    // Handle error if needed
  }
  display.clearDisplay();
  display.display();
}

void clearUI() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
}

void drawTitle(const char* title) {
  clearUI();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println(title);
  display.display();
}

void updateUIStateIndicators(bool q, bool qb) {
  // Draw Q/Q̅ indicators at bottom of screen
  // Simple example: redrawing Q states as rectangles or text
  clearUI();
  display.setCursor(0,10);
  display.print("Q: ");
  display.println(q ? "1" : "0");
  display.print("Q̅: ");
  display.println(qb ? "1" : "0");
  display.display();
}

// Example mode diagrams: In reality, you'd draw NAND gates, etc.

void drawSRMode() {
  display.setCursor(0,20);
  display.println("SR Latch Diagram:");
  display.println(" S ----> NAND ----> Q");
  display.println(" R ----> NAND ----> Q̅");
  display.display();
}

void drawDMode() {
  display.setCursor(0,20);
  display.println("D Latch Diagram:");
  display.println(" D & E gated into SR latch");
  display.display();
}

void drawJKMode() {
  display.setCursor(0,20);
  display.println("JK FF Diagram:");
  display.println(" J & Q̅, K & Q feedback into SR");
  display.display();
}

void drawTMode() {
  display.setCursor(0,20);
  display.println("T FF Diagram:");
  display.println(" T input toggles Q on each E/CLK");
  display.display();
}
