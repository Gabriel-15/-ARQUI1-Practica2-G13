#include <Password.h>
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x20,18,2);
LiquidCrystal_I2C lcd2(0x27,16,2);
////constantes para las filas y columnas del Pad
const byte rows =4;
const byte columns=3;
/////char que contendra la contraseña correcta
Password pass ="202113";
/////////////MATRIZ QUE CONTENDRA LOS BOTONES DEL PAD///////
char keys[rows][columns]  ={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
  };
/////vectores de pines a utilizar para el Pad
const byte rowPins[rows]={10,9,8,7};
const byte columnPins[columns]={13,12,11};
////////instancia del keypad con las variables creadas
Keypad keypad = Keypad(makeKeymap(keys),rowPins,columnPins,rows,columns);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd2.init();
  keypad.addEventListener(keypadEvent);
//  mensajePrincipal();
}

void loop() {
  // put your main code here, to run repeatedly:
//  Wire.beginTransmission(10);
//  Wire.write("hola");
//  Wire.endTransmission(); 
//  delay(1000); 
keypad.getKey();
}
 void keypadEvent(KeypadEvent eKey){
  switch(keypad.getState()){
  case PRESSED:
  lcd.print(eKey);
  switch(eKey){
    case '*': verificaPassword();break;
    case '#': lcd2.clear();lcd2.print("APAGADO");pass.reset();break;
    default: pass.append(eKey);
    }
    }
  }

  void verificaPassword(){
    if(pass.evaluate()){
      lcd2.clear();
      mensajeBienvenido();
      }else{
        lcd.clear();
        lcd2.clear();
        lcd2.print("INCORRECTO");
        pass.reset();
        }
    
    }

void mensajeBienvenido(){
      lcd2.print("BIENVENIDO");
      }
/////////////////MENSAJE PRINCIPAL LC1///////////////
//void mensajePrincipal(){
//   lcd.backlight();
//  lcd.setCursor(3,0);
//  lcd.print("CASA ACYE1");
//  lcd.setCursor(4,1);
//  lcd.print("A-G13-S2");
//  }
