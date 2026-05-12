#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int touchPin = D0;
int buzzer = D5;
bool beep = false;

void touchIn();

void testdrawchar(void);

void touchInteraction();


void setup() {
  pinMode(touchPin, INPUT);
  pinMode(buzzer, OUTPUT);
  // Serial.begin(115200);


  // if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
  //   Serial.println(F("SSD1306 allocation failed"));
  //   for(;;); // Don't proceed, loop forever
  // }
  // display.clearDisplay();
  // touchIn();
  // testdrawchar();
  // display.display();
  
}

void loop() {
  touchInteraction();
  // put your main code here, to run repeatedly:
}

void touchIn(){
  display.drawPixel(10, 10, WHITE);
  display.drawPixel(11, 11, WHITE);
  display.drawPixel(12, 12, WHITE);
  display.display();
  delay(1000);
}

void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  delay(2000);
}


void touchInteraction(){
  digitalWrite(buzzer,1);
  delay(1);
  digitalWrite(buzzer, 0);
  delay(1);
}