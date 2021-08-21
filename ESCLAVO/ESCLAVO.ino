#include <LiquidCrystal.h>


#include <Wire.h>
LiquidCrystal lcd(7,6,5,4,3,2);
String msj="";
void setup() {
  // put your setup code here, to run once:
  Wire.begin(10);
  Wire.onReceive(escuchar);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void escuchar(int numBytes){
  while(numBytes>0){
    char c = Wire.read();
    msj+=c;
    lcd.clear();
    numBytes--;
    } 
    lcd.setCursor(4,0);
   lcd.print(msj);
  }
