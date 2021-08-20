#include <Wire.h>

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
    Serial.print(c);
    numBytes--;
    } 
    Serial.println();
  }
