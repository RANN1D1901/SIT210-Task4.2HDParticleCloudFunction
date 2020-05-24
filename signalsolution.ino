

int led1 = A5; 
int led2=A4;
int led3=A3;

int signAl(String command);

void setup() 
{
    Particle.function("signAl",signAl);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}
void loop() {

}

void REDSIGNAL()
{

    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led1,HIGH);

}
void GREENSIGNAL()
{
    digitalWrite(led3,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
}

void BLUESIGNAL()
{
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
}
int signAl(String command)
{
  // look for the matching argument "coffee" <-- max of 64 characters long
  if(command == "red")
  {
    REDSIGNAL();
    return 1;
  }else if(command=="green")
  {
      GREENSIGNAL();
      return 1;
      
  }
  else if(command=="blue")
  {
      BLUESIGNAL();
      return 1;
      
  }
  else
  {
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    return -1;
      }
      
}

