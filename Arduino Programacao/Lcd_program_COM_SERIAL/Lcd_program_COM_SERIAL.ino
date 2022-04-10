#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int laster;
void setup(){
Serial.begin(50);
  lcd.begin(16,2);
}

void loop(){
  int oper;
lcd.setCursor(0,0);
//Print message
lcd.print("PI 2-Comunicacao");
//set cursor to column 0, line 2
//note line 2 is the secons row since the first row is 0
lcd.setCursor(0,2);
//print the number of seconds since reset;
if (Serial.available() > 0) {
                // read the incoming byte:
laster = Serial.read();
lcd.print(" Celsius ") ;               
lcd.print(laster);


oper = laster;

//Serial.println("if");
//Serial.println(laster);
}
oper= oper*2;
lcd.print("  ") ;               
lcd.print(oper);
//else{
//lcd.print("last ") ;
//lcd.print(" Celsius ") ;
//lcd.print(last) ;
//Serial.println("else");
//Serial.println(last);
//}

}
