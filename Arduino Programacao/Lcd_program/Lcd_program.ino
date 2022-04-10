#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){

  lcd.begin(16,2);
}

void loop(){
lcd.setCursor(0,0);
//Print message
lcd.print("medo nao e nada demais por favor");
//set cursor to column 0, line 2
//note line 2 is the secons row since the first row is 0
lcd.setCursor(0,2);
//print the number of seconds since reset;
lcd.print(millis()/1000);
}
