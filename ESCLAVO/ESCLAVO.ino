#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(10);
  Wire.onReceive(escuchar);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void escuchar(int numBytes){
  
  
  }
