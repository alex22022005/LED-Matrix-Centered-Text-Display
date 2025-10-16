#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>

const int WIDTH = 3;   // panels across
const int HEIGHT = 1;  // single row
const int TOTAL_WIDTH = WIDTH * PANEL_WIDTH;

SPIDMD dmd(WIDTH, HEIGHT);

void setup() {
  dmd.begin();
  dmd.setBrightness(255);
  dmd.selectFont(SystemFont5x7);
  dmd.clearScreen();
}

void loop() {
  const char *text = "EMBEDDED AND IOT LAB";

  // text width: 5px per char +1 spacing
  int textWidth = strlen(text) * 6;

  // vertical position: small offset to keep fully visible
  int yPos = 4;  // top margin for single-row display

  // horizontal floating effect: shift ±5 pixels
  int centerX = (TOTAL_WIDTH - textWidth) / 2;
  int offset = 0;
  int step = 1;

  while (true) {
    dmd.clearScreen();
    dmd.drawString(centerX + offset, yPos, text, GRAPHICS_NOR);
    delay(50);

    offset += step;
    if (offset > 18 || offset < -17) step = -step; // reverse direction
  }
}