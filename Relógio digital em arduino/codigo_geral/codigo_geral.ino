#include <math.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int s=0;int m=1;int h=0;      int ds=0; int dm=0;  int dh=0;
int control10=0;int control7=0;int control8=0; int control9=0;
int variacao=0;
int seglinha=0;int segcoluna=0;   int minlinha=0;int mincoluna=0;    int horlinha=0;int horcoluna=0;
int tipo=0; int mudar=0; int limite=0;
int modulo = 0;
int s1=0;

int contador=0;//***
int ponteiro=0;
int controla=0;

int despertar=0;int tempodespertar=0;int controldespertar=0; int pontdespertar=0;
int meiotempod=0; int i=0; int meiocontador=0;int controlbeep=0;

int mes=1; int dia=1; int ano=2014; int limitedia=30; int bissexto = 0; int anobase = 2014;
int dialinha=0; int diacoluna=0; int meslinha=0; int mescoluna=0; int anolinha=0; int anocoluna=0;

void setup(){

  lcd.begin(16,2);
  Serial.begin(9600); 
//pinMode(1,INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  
}

double Thermistor(int RawADC) {
  double Temp;
  
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;           // Convert Kelvin to Celcius
  return Temp;
}



void loop(){
 
 // variavel de temperatura 
  double temp = Thermistor(analogRead(0));  // Read sensor on Pin 0
  
  
  //SERTAR VARIAVEIS DE SENSORES ----------------------------------------
 //int sensorVal1 = digitalRead(1);
 int sensorVal7 = digitalRead(7);
 int sensorVal8 = digitalRead(8);
 int sensorVal9 = digitalRead(9);
 int sensorVal10 = digitalRead(10);


 

  if(modulo==2){modulo=0;}                    
                      
 
 if(modulo==0){//  ============================= MODULO HORÁRIO ==================
  
  
  
  if(s1<1){// RELÓGIO CONTADOR -------------------------------------------
   //delay(1000);

  mudar=0;// limpa o botão de mudanca para permitir alterar dados sem alterar Anos, basta sair do modo edição.
 //============================== BOTAO DE TRANSIÇÃO ===================== SEM ESTAR NO MODO EDIÇÃO...
  if(control9==0){ // FORMULA GERAL
      if (sensorVal9 == LOW){ // QUANDO APERTAR BOTÃO
        control9= control9 + 1;
                             }//                  
        modulo=modulo + control9; // VARIAVEL QUE QUERO           
                      }//                        
      if(control9>=1){              
      if(sensorVal9 == HIGH){
       control9=0;
                             }
                      }
                      
//CONTADOR
      
     //if(s<=59) {
     //  s = s + 1;
     //       }
                          
     contador = (millis()/1000);
                     // FORMULA PARA SOMA NA VARIACAO DE TEMPO - MILLIS
      if(ponteiro==0){ // variavel só altera uma vez a cada rotina
      controla = contador;//iguala variaveis
      
        ponteiro= ponteiro + 1;//soma 1
                                              
        s=s + ponteiro; // soma 1 ao segundo           
                      }                        
      if(ponteiro>=1){              
      if(controla != contador){// variavel somente se altera a cada segundo
       ponteiro=0;             // me dando 1 seg de vantagem para reinicio
                             }
                      } 
                            
                            
                            
                            
// SEGUE CONFIGURACOES DE SEGUNDOS 

      seglinha=14;
      segcoluna=2;
    lcd.setCursor(seglinha,segcoluna);
    lcd.print(s);
    if(s<=9){
  lcd.setCursor(seglinha,segcoluna);
  lcd.print("0");
  lcd.setCursor(seglinha+1,segcoluna);
    lcd.print(s);
              }
    
     if(s>=60){ // SOMADOR SEGUNDOS-MINUTO
       s=0; 
       m=m+1;
     //LIMPAR TELA:
       lcd.setCursor(seglinha,segcoluna);
       lcd.print("00");    
            }              
  
//SEGUE CONFIGURACAO DE MINUTOS  

    minlinha=11;
    mincoluna=2;
  lcd.setCursor(minlinha,mincoluna);
  lcd.print(m);
  if(m<=9){
  lcd.setCursor(minlinha,mincoluna);
  lcd.print("0");
  lcd.setCursor(minlinha+1,mincoluna);
  lcd.print(m);
           }
           
  if(m>=60){   //SOMADOR MINUTOS-HORAS
    m=0;
    h=h+1;
     //LIMPAR TELA:
       lcd.setCursor(minlinha,mincoluna);
       lcd.print("00");
          }           
  
//SEGUE CONFIGURACAO DE HORAS 

    horlinha=8;
    horcoluna=2;
  lcd.setCursor(horlinha,horcoluna);
   lcd.print(h);
   if(h<=9){
  lcd.setCursor(horlinha,horcoluna);
  lcd.print("0");
  lcd.setCursor(horlinha+1,horcoluna);
   lcd.print(h);
           }
           
           if(h>=24){   //SOMADOR MINUTOS-HORAS
    h=0;
    dia=dia+1;
     //LIMPAR TELA:
       lcd.setCursor(horlinha,horcoluna);
       lcd.print("00");
          }           

   
// SETOR DE CONFIGURAÇÃO DE CALENDÁRIO ===================================================

  //configuração de dia
    dialinha=6;
    diacoluna=0;
  lcd.setCursor(dialinha,diacoluna);
   lcd.print(dia);
   if(dia<=9){
  lcd.setCursor(dialinha,diacoluna);
  lcd.print("0");
  lcd.setCursor(dialinha+1,diacoluna);
   lcd.print(dia);
           }
   if(dia>=limitedia){   //SOMADOR MINUTOS-HORAS
    dia=1;
    mes=mes+1;
     //LIMPAR TELA:
       lcd.setCursor(dialinha,diacoluna);
       lcd.print("00");
          }
    lcd.setCursor(dialinha-1,diacoluna);
       lcd.print(" ");
  // configuração de mes =================================ESPECIAL  MESES
  meslinha=9;
    mescoluna=0;
  lcd.setCursor(meslinha,mescoluna);
   lcd.print(mes);
   if(mes<=9){
  lcd.setCursor(meslinha,mescoluna);
  lcd.print("0");
  lcd.setCursor(meslinha+1,mescoluna);
   lcd.print(mes);
           }
   if(mes>=13){   //SOMADOR MES - ANO ===== comeca em 1
    mes=1;
    ano=ano+1;
     //LIMPAR TELA:
       lcd.setCursor(meslinha,mescoluna);
       lcd.print("00");
          }
          
      //limite dias por mes
    if(mes==1){ limitedia = 32; }
    if(mes==2 && bissexto == 0){ limitedia = 29; }
    if(mes==2 && bissexto == 1){ limitedia = 30; }   // ======================== ESPECIAL BISSEXTO === até 29
    if(mes==3){ limitedia = 32; }
    if(mes==4){ limitedia = 31; }
    if(mes==5){ limitedia = 32; }
    if(mes==6){ limitedia = 31; }
    if(mes==7){ limitedia = 32; } 
    if(mes==8){ limitedia = 32; }
    if(mes==9){ limitedia = 31; }
    if(mes==10){ limitedia = 32; } 
    if(mes==11){ limitedia = 31; }
    if(mes==12){ limitedia = 32; }     
    
    
 // configuração de ano ================================= ESPECIAL BISSEXTO
   anolinha=12;
    anocoluna=0;
  lcd.setCursor(anolinha,anocoluna);
   lcd.print(ano);
   lcd.setCursor(anolinha-1,anocoluna);// limpeza do "D" do despertador
   lcd.print(" ");
   if( ano % 4 == 0){  if( ano % 100 != 0 ){bissexto = 1;} }
   if(ano % 400 == 0)
    {bissexto = 1;}
    
   if(ano %4 != 0){bissexto = 0;} 
   
   // SINAL DE GRAUS CELSIUS
  
  lcd.setCursor(0,2);
  lcd.print(temp);
  lcd.setCursor(5,2);
  lcd.print("'C");

//SEPARADOR DE HORARIO
  lcd.setCursor(horlinha+2,2);
  //Print message
  lcd.print(":");
  
  lcd.setCursor(minlinha+2,2);
  //Print message
  lcd.print(":");
  
  //SEPARADOR DE DATA
  lcd.setCursor(dialinha+2,0);
  //Print message
  lcd.print("/");
  
  lcd.setCursor(meslinha+2,0);
  //Print message
  lcd.print("/");
  
 }
 
 
  //ATIVAR MODO DE EDICAO - FAZENDO S1=1 ----------------------------------
  if(s1<1){
      if(control7==0){ // FORMULA GERAL
      if (sensorVal7 == LOW){ // QUANDO APERTAR BOTÃO
        control7= control7 + 1;
                             }//                  -------
        s1=s1 + (control7); // VARIAVEL QUE QUERO VARIAR                 
                      }//                        -------
      if(control7>=1){              
      if(sensorVal7 == HIGH){
       control7=0;
                             }
                      }
          } 
            
  
  if(s1>=1){ //---------------  MODO EDIÇÃO ATIVA -------------------------------
       
    
    // CONTROLE DE BOTÃO - SOMA - EVITAR SOMA POR MILISEGUNDOS ----------------------
      //SOMA À VARIAVEL  APENAS A VARIAÇÃO DO BOTÃO ------- FORMULA GERAL---------
      if(control10==0){
      if (sensorVal10 == LOW){ // QUANDO APERTAR BOTÃO
        control10= control10 + 1;
                             }
        variacao=variacao+control10; // VARIAVEL QUE QUERO VARIAR      VARIAÇÃO            
                      }
      if(control10>=1){              
      if(sensorVal10 == HIGH){
       control10=0;                    
                             }
                      }                  
            
     if(control7==0){ // FORMULA GERAL
      if (sensorVal7 == LOW){ // QUANDO APERTAR BOTÃO
        control7= control7 + 1;
                             }//                  ---------------------------------
        s1=s1 - (control7); // VARIAVEL QUE QUERO VARIAR --- SAI DO MODO EDIÇÃO -----                
                      }//                        --------------------------------
      if(control7>=1){              
      if(sensorVal7 == HIGH){
       control7=0;
                             }
                      }
     
     
     if(mudar<6){//------------------------ BOTAO DE MUDANCA----------
     
     if(control8==0){ // FORMULA GERAL
      if (sensorVal8 == LOW){ // QUANDO APERTAR BOTÃO
        control8= control8 + 1;
                             }//                  -------------------------------
        mudar=mudar + (control8); // ------------------ TANSICAO DA EDICAO HH-MM-SS----                
                      }//                        --------------------------------
      if(control8>=1){              
      if(sensorVal8 == HIGH){
       control8=0;
                             }
                      }
                 }
      if(mudar==6){mudar=0;}        
                 
     
     
     if(mudar==0){ // MUDAR = 0  ---  EDICAO DE SEGUNDOS----------
       limite=60;
        lcd.setCursor(seglinha,segcoluna);
      lcd.print(s);  

          if(variacao>=limite){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=0;
           
           lcd.setCursor(seglinha,segcoluna);// limpeza
           lcd.print("0 ");
           
              }
            
            
            
       // tenho uqe limitar com a função do botão, criando uma variavel de estado para igualar a "variação" ao valor original apenas 1 vez    
            
                           
      s=variacao;                         
                 }
     
     if(mudar==1){ // MUDAR = 1  ---  EDICAO DE MINUTOS ----------
       limite=60;
        lcd.setCursor(minlinha,mincoluna);
      lcd.print(m);  

          if(variacao>=limite){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=0;
           lcd.setCursor(minlinha,mincoluna);
           lcd.print("0 ");
                              } 
       m=variacao;            
                              
                 }
                 
        if(mudar==2){ // MUDAR = 2  ---  EDICAO DE HORAS ----------
       limite=24;
        lcd.setCursor(horlinha,horcoluna);
      lcd.print(h);  

          if(variacao>=limite){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=0;
           lcd.setCursor(horlinha,horcoluna);
           lcd.print("0 ");
                              } 
       h=variacao;            
                              
                 }         
     
      if(mudar==3){ // MUDAR = 3  ---  EDICAO DE DIAS ----------
       limite=limitedia;
        lcd.setCursor(dialinha,diacoluna);
      lcd.print(dia);  

          if(variacao>=limite || variacao == 0){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=1;
           lcd.setCursor(dialinha,diacoluna);
           lcd.print("0 ");
                              } 
       dia = variacao;            
                              
                 }                   
     
      if(mudar==4 ){ // MUDAR = 4  ---  EDICAO DE MES ----------
       limite=13;
        lcd.setCursor(meslinha,mescoluna);
      lcd.print(mes);  

          if(variacao>=limite || variacao == 0){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=1;
           lcd.setCursor(meslinha,mescoluna);
           lcd.print("0 ");
                              } 
       mes = variacao;            
                              
                 }
                 
       if(mudar==5){ // MUDAR = 5  ---  EDICAO DE ANOS ----------
       
        lcd.setCursor(anolinha,anocoluna);
      lcd.print(ano);  

      ano = anobase + variacao;            
                              
                 }
    // COLOCAR MUDAR DE 3 A 5   - DIA MES E ANO ======================================================
    
    
    
    /*PISCAR
    if((millis()%2)==0){
    lcd.setCursor(seglinha,segcoluna);
    lcd.print("  ");
                        }
    if((millis()%7)==0){
    lcd.setCursor(seglinha,segcoluna);
    lcd.print(s);                     
                        }
     */                     
                           
                                       }
                                       
      //==============DESPERTADOR===== COMPARADOR==========
  //=============================================================
  
  
    
    
    if(dh==h){
      if(dm==m){
        //if(ds>s){
        despertar=1;//========================= VERIFICADOR DE HORÁRIO =======
                //}
               }
             }
  
  if(despertar==1){
    
    if (sensorVal8 == LOW){ // QUANDO APERTAR BOTÃO ===== DESLIGAR O SOM ====================
        despertar = 0;
                             }
  
  //=============================================================================  
    meiocontador=millis()/100; // REDUZINDO O TEMPO POR SEGUNDO
    if(i==0){
      meiotempod=meiocontador;
      i=i+1;
      controlbeep=controlbeep +i; // CONTROLA O SOM
    }
     if(i>=1){              
      if(meiotempod != meiocontador){// variavel somente se altera a cada segundo
       i=0;             // me dando 1/10 seg de vantagem para reinicio
                             }
                      }
 //===============================================================================     
    if(tempodespertar%2==0)pinMode(13,LOW);else{
    
    if(controlbeep%2==0){
        pinMode(13,HIGH);}
      if(controlbeep%2!=0){
        pinMode(13,LOW);
                        }     
    }
  
   //=========================================================================   
   if(pontdespertar==0){ // variavel só altera uma vez a cada rotina
      controldespertar = contador;//iguala variaveis
      
        pontdespertar= pontdespertar + 1;//soma 1
                                              
        tempodespertar=tempodespertar + pontdespertar; // soma 1 ao segundo           
                      }                        
      if(pontdespertar>=1){              
      if(controldespertar != contador){// variavel somente se altera a cada segundo
       pontdespertar=0;             // me dando 1 seg de vantagem para reinicio
                             }
                      }
 //=============================================================================
      if (tempodespertar==31){ 
        despertar=0;tempodespertar=0;
                             } 
                             
                  }
      
     if(despertar==0){pinMode(13,LOW);}
  
  
     
                         
 }//=======================================FIM DO DESPERTADOR(SOM) ==============
 
 
 
 
 if(modulo==1){//====================== MODULO DESPERTADOR ====================
   
   //==========================COPIA MODULO 1 PARA QUE RELOGIO NÃO PARE ========
   
  contador = (millis()/1000);
                     // FORMULA PARA SOMA NA VARIACAO DE TEMPO - MILLIS
      if(ponteiro==0){ // variavel só altera uma vez a cada rotina
      controla = contador;//iguala variaveis
      
        ponteiro= ponteiro + 1;//soma 1
                                              
        s=s + ponteiro; // soma 1 ao segundo           
                      }                        
      if(ponteiro>=1){              
      if(controla != contador){// variavel somente se altera a cada segundo
       ponteiro=0;             // me dando 1 seg de vantagem para reinicio
                             }
                      } 
                      
       // SEGUE CONFIGURACOES DE SEGUNDOS     
     if(s>=60){ // SOMADOR SEGUNDOS-MINUTO
       s=0; 
       m=m+1;       
            }              
  
//SEGUE CONFIGURACAO DE MINUTOS  
  if(m>=60){   //SOMADOR MINUTOS-HORAS
    m=0;
    h=h+1;     
          }           
  
//SEGUE CONFIGURACAO DE HORAS 
   if(h>=24){   //SOMADOR HORAS-DIAS
    h=0;
    //d=d+1;
            }               
   
   //=========================FIM DA COPIA DO MODULO 1 =========================
   
   
   
   //ATIVAR MODO DE EDICAO 
  if(s1<1){
      if(control7==0){ // FORMULA GERAL
      if (sensorVal7 == LOW){ 
        control7= control7 + 1;
                             }           
        s1=s1 + (control7);          
                      }                     
      if(control7>=1){              
      if(sensorVal7 == HIGH){
       control7=0;
                             }
                      }
                      
       //============================== BOTAO DE TRANSIÇÃO ===================== SEM ESTAR NO MODO EDIÇÃO...
  if(control9==0){ // FORMULA GERAL
      if (sensorVal9 == LOW){ // QUANDO APERTAR BOTÃO
        control9= control9 + 1;
                             }//                  
        modulo=modulo + control9; // VARIAVEL QUE QUERO           
                      }//                        
      if(control9>=1){              
      if(sensorVal9 == HIGH){
       control9=0;
                             }
                      }               
                      
          }
          
    if(s1>=1){//=====================MODO EDICAO ATIVA===============
    
    if(control10==0){
      if (sensorVal10 == LOW){ // QUANDO APERTAR BOTÃO
        control10= control10 + 1;
                             }
        variacao=variacao+control10; // VARIAVEL QUE QUERO VARIAR                  
                      }
      if(control10>=1){              
      if(sensorVal10 == HIGH){
       control10=0;                    
                             }
                      }
                      
      if(control7==0){ // FORMULA GERAL
      if (sensorVal7 == LOW){ // QUANDO APERTAR BOTÃO
        control7= control7 + 1;
                             }//                  ---------------------------------
        s1=s1 - (control7); // VARIAVEL QUE QUERO VARIAR --- SAI DO MODO EDIÇÃO -----                
                      }//                        --------------------------------
      if(control7>=1){              
      if(sensorVal7 == HIGH){
       control7=0;
                             }
                      }                
      
      if(mudar<3){//------------------------ BOTAO DE MUDANCA----------
     
     if(control8==0){ // FORMULA GERAL
      if (sensorVal8 == LOW){ 
        control8= control8 + 1;
                             }                 
        mudar=mudar + (control8);                 
                      }//                        
      if(control8>=1){              
      if(sensorVal8 == HIGH){
       control8=0;
                             }
                      }
                 }
                 
       if(mudar==3){mudar=0;}                                                 
                             
                               
       if(mudar==0){ // MUDAR = 0  ---  EDICAO DE SEGUNDOS-DESPERTADOR---------
       limite=60;
        lcd.setCursor(seglinha,segcoluna);
      lcd.print(ds);  

          if(variacao>=limite){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=0;
           
           lcd.setCursor(seglinha,segcoluna);// limpeza
           lcd.print("0 ");
           
                               }                            
      ds=variacao;                         
                 }
     
     if(mudar==1){ // MUDAR = 1  ---  EDICAO DE MINUTOS --DESPERTADOR--------
       limite=60;
        lcd.setCursor(minlinha,mincoluna);
      lcd.print(dm);  

          if(variacao>=limite){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=0;
           lcd.setCursor(minlinha,mincoluna);
           lcd.print("0 ");
                              } 
       dm=variacao;            
                              
                 }
                 
        if(mudar==2){ // MUDAR = 2  ---  EDICAO DE HORAS ---DESPERTADOR-------
       limite=24;
        lcd.setCursor(horlinha,horcoluna);
      lcd.print(dh);  

          if(variacao>=limite){// VARIACAO NAO DEVE ULTRAPASSAR LIMITE
           variacao=0;
           lcd.setCursor(horlinha,horcoluna);
           lcd.print("0 ");
                              } 
       dh=variacao;            
                              
                 }                                               
                                
                                                  }  
                                                    
   //-----------------------------STATUS DE  DESPERTADOR-----------------------
   lcd.setCursor(horlinha,horcoluna);
  lcd.print(dh);
  if(dh<=9){
  lcd.setCursor(horlinha+1,horcoluna);
  lcd.print(" ");
      }
      
   lcd.setCursor(minlinha,mincoluna);
  lcd.print(dm);
  if(dm<=9){
  lcd.setCursor(minlinha+1,mincoluna);
  lcd.print(" ");
      }
  
   lcd.setCursor(seglinha,segcoluna);
  lcd.print(ds);
  if(ds<=9){
  lcd.setCursor(seglinha+1,segcoluna);
  lcd.print(" ");
  }
  
  lcd.setCursor(horlinha-3,0);
  //Print message
  lcd.print("Despertador");
  
   
                      
                      
 }
        
  //STATUS DE BOTOES NA TELA ------------------------------------
 /*   lcd.setCursor(0,0);
  lcd.print("a");
    lcd.setCursor(1,0);
  lcd.print(control7);
  
    lcd.setCursor(3,0);
  lcd.print("b");
    lcd.setCursor(4,0);
  lcd.print(control8);  
    
    lcd.setCursor(0,2);
  lcd.print("c");
    lcd.setCursor(1,2);
  lcd.print(control9);
    
    lcd.setCursor(3,2);
  lcd.print("d");
    lcd.setCursor(4,2);
  lcd.print(despertar);
  
  
  lcd.setCursor(6,2);
  //Print message
  lcd.print(variacao);
  
  */
  lcd.setCursor(0,0);
  //Print message
  lcd.print(s1);
  
 lcd.setCursor(2,0);
  //Print message
  lcd.print(modulo);
 
 lcd.setCursor(4,0);
  //Print message
  lcd.print(bissexto);
 

 
}

