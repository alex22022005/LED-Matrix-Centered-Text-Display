#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>

const int WIDTH = 3;   // number of panels across
const int HEIGHT = 1;  // number of panels down
const int TOTAL_WIDTH = WIDTH * PANEL_WIDTH; // use library's PANEL_WIDTH

SPIDMD dmd(WIDTH, HEIGHT);

void setup() {
  dmd.begin();
  dmd.setBrightness(255);
  dmd.selectFont(SystemFont5x7);
  dmd.clearScreen();

  // Text to display
  const char *line1 = "EMBEDDED AND";
  const char *line2 = "IOT LAB";

  // Calculate approximate text width (5px per char + 1px spacing)
  int line1Width = strlen(line1) * 6; // 5px font +1px spacing
  int line2Width = strlen(line2) * 6;

  // Calculate x positions for centering
  int x1 = (TOTAL_WIDTH - line1Width) / 2;
  int x2 = (TOTAL_WIDTH - line2Width) / 2;

  // Draw centered text
  dmd.drawString(x1, 0, line1, GRAPHICS_NOR);
  dmd.drawString(x2, 8, line2, GRAPHICS_NOR);
}

void loop() {
  // Static display, nothing needed here
}
