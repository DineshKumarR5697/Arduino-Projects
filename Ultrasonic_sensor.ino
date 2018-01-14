#define echoPin 11
#define trigPin 12
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int distance,duration;
  digitalWrite(trigPin,HIGH);
  delay(100);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  Serial.print("");
  delay(1000);
}
