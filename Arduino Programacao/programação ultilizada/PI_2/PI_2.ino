   int pin = A0;
   int tempc = 0; // variavel que guardará valor médio de temperatura
   float samples[8]; /* vetor que auxiliará na contagem e armazenamento
                        da média de temperaturas                 */

   int i; // variavel para a contagem

   void setup()
  {

    Serial.begin(50); /* velocidade de comunicação serial 
  }                    configurada para 50 bytes/sec          */

   void loop()
  {
     for(i=0;i<=7; i++){
       
    samples[i]= analogRead(pin)*0.4887585532746823069403714565;
    /* executa a conversao da leitura analógia para valores digitais
       ao tempo que guarda o resultado no vetor     */    
   tempc = tempc + samples[i]; // soma cada resultado a variavel tempc
                }

   tempc= tempc/8; // tira uma média para filtrar melhor a medida
   
   Serial.write(tempc);// escreve o resultado do sensor na porta TX


   tempc=0; // reseta a variavel para que nao atrapalhe na medicao
   }

