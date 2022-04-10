int pin = A0;
int tempc = 0;
float samples[8];

int i;

void setup()
{

 Serial.begin(50);
}

void loop()
{
  for(i=0;i<=7; i++){
  samples[i]= analogRead(pin)*0.4887585532746823069403714565;
tempc = tempc + samples[i];
                }

//Serial.print(" analogread: ");
//Serial.println(analogRead(pin));

tempc= tempc/8;

//Serial.print(" temperatura: ");
//Serial.println(tempc);
Serial.write(tempc);


tempc=0;
}

