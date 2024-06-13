int l1green = 5;
int l2green = 6;

int l1red = 7;
int l2red = 8;

int buzzer = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(l1green, OUTPUT);
  pinMode(l2green, OUTPUT);
  pinMode(l1red, OUTPUT);
  pinMode(l2red, OUTPUT);
  pinMode(buzzer, OUTPUT); 
  digitalWrite(buzzer, LOW);
}

void normal()
{
  if(Serial.available()>0)
  {
    int pc_data = Serial.parseInt();
    if(pc_data == 1)
    {
      digitalWrite(buzzer, HIGH);
            delay(2000);
      digitalWrite(buzzer, LOW);
      lane1();
    }
    else if(pc_data == 2)
    {
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      lane2();
    } 
  }
  else
  {
  digitalWrite(l1green, HIGH);
  digitalWrite(l2green, LOW);
  digitalWrite(l1red, LOW);
  digitalWrite(l2red, HIGH);
  delay(2000);
  digitalWrite(l1green, LOW);
  digitalWrite(l2green, HIGH);
  digitalWrite(l1red, HIGH);
  digitalWrite(l2red, LOW);
  delay(2000);
 }
}
void loop()
{
normal();
}

void lane1()
{
  digitalWrite(l1green, HIGH);
  digitalWrite(l2green, LOW);
  digitalWrite(l1red, LOW);
  digitalWrite(l2red, HIGH);
  delay(10000);
}

void lane2()
{
  digitalWrite(l1green, LOW);
  digitalWrite(l2green, HIGH);
  digitalWrite(l1red, HIGH);
  digitalWrite(l2red, LOW);
  delay(10000);

}
