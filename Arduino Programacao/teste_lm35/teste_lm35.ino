int pin = A0;
float tempc = 0;
float samples[8];

int i;

void setup()
{

 Serial.begin(9600);
}

void loop()
{
  for(i=0;i<=7; i++){
  samples[i]= analogRead(pin)*0.4887585532746823069403714565;
tempc = tempc + samples[i];
                }

Serial.print(" samples: ");
Serial.println(samples[7]);

tempc= tempc/8;

Serial.print(" temperatura: ");
Serial.println(tempc);


delay(500);
tempc=0;
}
