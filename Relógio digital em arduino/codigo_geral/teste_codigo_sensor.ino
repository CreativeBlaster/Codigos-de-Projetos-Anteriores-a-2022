#include <math.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);


void setup() {
  lcd.begin(16,2);
  Serial.begin(9600); 


}

double Thermistor(int RawADC) {
  double Temp;
  
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;           // Convert Kelvin to Celcius
  return Temp;
}

void printTemp(void) {
 
  double temp = Thermistor(analogRead(0));  // Read sensor on Pin 0
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature is:");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print(" C, ");

}

void loop() {
  // put your main code here, to run repeatedly:
 printTemp();
  delay(1000);
}
