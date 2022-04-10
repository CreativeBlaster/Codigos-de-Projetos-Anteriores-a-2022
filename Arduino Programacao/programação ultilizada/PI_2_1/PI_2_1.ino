
   #include <LiquidCrystal.h>// inclui a biblioteca do display LCD

   LiquidCrystal lcd(12,11,5,4,3,2);//inicia a variavel indicando pinos                        

   void setup(){
  
   Serial.begin(50); // indica velocidade de comunicacao

     lcd.begin(16,2); // inicia a interface do dysplay indicando seu tamanho
   }

   void loop(){  
   lcd.setCursor(0,0);// indica a linha e coluna de início

   lcd.print("PI 2-Comunicacao");//Imprimindo messagem
   //set cursor to column 0, line 2
   //note que a linha 2 é a segunda linha desde que a primeira linha seja 0
   lcd.setCursor(0,2); // indica o ponto de escrita como coluna 0 linha 2

   if (Serial.available() > 0) {// verifica se há ou não bytes na entrada RX
                // Lendo bytes de entrada e imprimindo na tela
   lcd.print(" Celsius ") ;               
   lcd.print(Serial.read());
    }
   }
