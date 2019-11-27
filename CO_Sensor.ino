#include <Wire.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() 
{
  pinMode(A0,INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  Serial.begin(9600);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30,30);
  display.setTextSize(1);
  display.print("Checking...");
  display.display();
 
}

void loop() 
{
   while(count(30)!=30);

while(true)
{
  //Formula to Calculate PPM  
   float input = analogRead(A0);
   float sensor = input*5/1023;
   float  ppm = 3.027*exp(1.0698*(sensor));
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(50,50);
  display.print(ppm);
  display.display();
  display.clearDisplay();
  delay(500);
 
if(ppm <= 9.9)
{  
  display.clearDisplay();  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,5);
  display.println("Fresh Air");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(27,35);
  display.println("CO value(ppm)");
  display.display();
 }

else if(ppm > 9.9)
{ 
  display.clearDisplay();  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(2,5);
  display.println("WEAR MASK!");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(27,35);
  display.println("CO value(ppm)");
  display.display();
}
}
}


int count(int j)
{
  int i;
  for(i=0; i<j; i++)
{
  delay(1000);
 }
  return i;
}
