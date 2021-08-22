#include <LiquidCrystal.h>


#include <Wire.h>
LiquidCrystal LCD(13,12,11,10,9,8);


int direccion1=10;
int direccion2=0x49;// 0x49;


void setup() {
  // put your set
Wire.begin(direccion1);
Wire.onReceive(escuchar);




Serial.begin(9600);
//Wire.begin( DS1621_ADDRESS );
//Wire.onReceive(escucharSensor);

}

void loop() {
  // put your main code here, to run repeatedly:

}
void sensor(int cantidadBytes){
  LCD.clear();
  while(cantidadBytes>0){
    char c=Wire.read();
    LCD.print(c);
    cantidadBytes--;
    }
  }
//  }
void escuchar(int numBytes){
  LCD.clear();
  while(numBytes>0){
   char c = Wire.read();
    LCD.print(c);
    numBytes--;
    } 
  }
