#include <Password.h>
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

///direccion para el sensor de temperatura
int DS1621_ADDRESS =  0x49;
int temperature=0;
boolean banderaTemperatura = false;

////LETRA Ñ

 byte enie[8] =
 {
 0b00001111,
 0b00000000,
 0b00011001,
 0b00011001,
 0b00010101,
 0b00010101,
 0b00010011,
 0b00010011
 };

LiquidCrystal_I2C lcd(0x20,18,2);
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
    
keypad.addEventListener(keypadEvent);
   Wire.begin();
   mensajePrincipal();
   
 }

void loop() {
keypad.getKey();
}

//METODO PARA VALIDACION DE CONTRASEÑA
 void keypadEvent(KeypadEvent eKey){
 
  switch(keypad.getState()){
  case PRESSED:
  switch(eKey){
    case '*': verificaPassword();break;
    case '#': 
    
    break;
    default: pass.append(eKey);
    }
    
  }
  }

  void verificaPassword(){
    
    if(pass.evaluate()){
     mensajeBienvenido();
     while(true){
     obtenerTemperatura();
     
        if(keypad.isPressed('#')){
       ///////////AQUI VA LO QUE SE TIENE QUE REALIZAR DESPUES DE PRECIONAR LA TECLA #   apagarMotores();
          break;     
          }
      }
     }else{
       mensajeError();
        pass.reset();
        }
    
    }
///MENSAJE DE CONTRASEÑA INCORRECTA
void mensajeError(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("ERROR EN ");
  lcd.setCursor(2,1);
  lcd.print("CONTRASE");
  lcd.write(1);
  lcd.print("A");
  }
  ///MENSAJE DE CONTRASEÑA CORRECTA
void mensajeBienvenido(){
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("BIENVENIDO A");
      lcd.setCursor(6,1);
      lcd.print("CASA");
      }
/////////////////MENSAJE PRINCIPAL LC1///////////////
void mensajePrincipal(){
  lcd.setCursor(3,0);
  lcd.print("CASA ACYE1");
  lcd.setCursor(4,1);
  lcd.print("A-G13-S2");
  }

  //ENVIO DE MENSAJE A ESCLAVO

 //METODO QUE CONTROLARA EL SENSOR PARA ENVIAR LOS DATOS AL ARDUINO ESCLAVO
 
void obtenerTemperatura() {
  
  Wire.beginTransmission(DS1621_ADDRESS);
  Wire.write(0xAC);
  Wire.write(0x02);
  Wire.beginTransmission(DS1621_ADDRESS);
  Wire.write(0xEE);
  Wire.endTransmission();
  
  delay(1000);
  Wire.beginTransmission(DS1621_ADDRESS); // conexxion con el DS1621
  Wire.write(0xAA);                       // comando para leer la temperatura
  Wire.endTransmission();            // send repeated start condition
  Wire.requestFrom(DS1621_ADDRESS, 2);    // request 2 bytes from DS1621 and release I2C bus at end of reading
  temperature=Wire.read();
  
 
  Wire.endTransmission();
  
  Wire.beginTransmission(10);
  Wire.write(temperature);
  Wire.endTransmission();
   
}
  
