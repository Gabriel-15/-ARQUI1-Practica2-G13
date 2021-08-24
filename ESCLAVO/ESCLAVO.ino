
#include <LiquidCrystal.h>
#include <Wire.h>

// Definimos las constantes
#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD



LiquidCrystal LCD(13,12,11,10,9,8);
int pin1=7;
int pin2=8;

//int DS1621_ADDRESS =0x49;// 0x49;
byte grados[8]=
{
 0b00001100,
 0b00010010,
 0b00001100,
 0b00000000,
 0b00000000,
 0b00000000,
 0b00000000,
 0b00000000
   };

void setup() {
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  // put your set
  LCD.begin(COLS,ROWS);
  LCD.setCursor(4,0);
  LCD.print("APAGADO");

  LCD.createChar(1,grados);
  Serial.begin(9600);

Wire.begin(10);
Wire.onReceive(escuchar);

} 
void loop() {
  // put your main code here, to run repeatedly:

}
//  }
void escuchar(int numBytes){ 
  
  while(numBytes>0){
    
   int c = Wire.read();
  
     if(c<=18){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("TEMP: ");
    LCD.print(c);
    LCD.write(1);
    LCD.print("C");
    LCD.setCursor(0,1);
    LCD.print("Nivel: 1");  
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    }else if(c>18&&c<25){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("TEMP: ");
    LCD.print(c);
    LCD.write(1);
    LCD.print("C");
    LCD.setCursor(0,1);
    LCD.print("Nivel: 2");   
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
      }else if((c>=25&&c<75)||(c>75)){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("TEMP: ");
    LCD.print(c);
    LCD.write(1);
    LCD.print("C");
    LCD.setCursor(0,1);
    LCD.print("Nivel: 3");   
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
        }
    numBytes--;
  } 
    
  }
