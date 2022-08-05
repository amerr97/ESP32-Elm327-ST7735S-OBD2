#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include "bitmaps.h"
#include "bitmapsLarge.h"

#define TFT_CS        5
#define TFT_RST        4 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         2

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));
 tft.initR(INITR_BLACKTAB);
  tft.setRotation(0);
  tft.fillScreen(ST7735_BLACK);


//Case 2: Multi Colored Images/Icons
  int h = 160,w = 128, row, col, buffidx=0;
  for (row=0; row<h; row++) { // For each scanline...
    for (col=0; col<w; col++) { // For each pixel...
      //To read from Flash Memory, pgm_read_XXX is required.
      //Since image is stored as uint16_t, pgm_read_word is used as it uses 16bit address
      tft.drawPixel(col, row, pgm_read_word(evive_in_hand + buffidx));
      buffidx++;
    } // end pixel
  }
  delay(5000);
  // Use this initializer if using a 1.8" TFT screen:
 // tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  tft.setRotation(1); // set display orientation 
}

void loop() {
  tft.fillScreen(ST77XX_BLACK);
  print_text(20,5,"1.54",5,ST77XX_GREEN);
  print_text(70,50,"BAR",2,ST77XX_GREEN);
  print_text(5,90,"Temp motora: 81'C",1,ST77XX_WHITE);
  print_text(5,100,"Temp usisa: 30'C",1,ST77XX_BLUE);
  print_text(146,116,"AM",1,ST77XX_WHITE);
  

  delay(5000);
  
  
}

void print_text(byte x_pos, byte y_pos, char *text, byte text_size, uint16_t color) {
  tft.setCursor(x_pos, y_pos);
  tft.setTextSize(text_size);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
