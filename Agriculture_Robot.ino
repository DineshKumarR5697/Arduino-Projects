/* Agriculture Robot for object detection in the field 
and measure the temperature */
#define LM1 4       // left motor
#define LM2 5       // left motor
#define RM1 6       // right motor
#define RM2 7       // right motor
#define echoPin 11
#define trigPin 12
char state;
float tempC;
int reading;
int tempPin=0;


void setup()
{
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  analogReference(INTERNAL);
}
void loop()
{ 
  int distance,duration;
  digitalWrite(trigPin,HIGH);
  delay(100);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  Serial.print("");
  reading=analogRead(tempPin);
  tempC=reading/9.31;
  Serial.println("temp=");
  Serial.println(tempC);
  delay(1000);
  if (Serial.available() > 0) 
  {
    state = Serial.read();
  }
  if (distance>=30)
 {
  // Move Forward
  if (state == 'F' || state == 'f')
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  // Move Left
  if (state == 'L' || state == 'l')
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  // Move Right
   if (state == 'R' || state == 'r')
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }
  // Move Reverse
  if (state == 'E' || state == 'e')
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }
  // Stop
  if (state == 'S' || state == 's')
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
else
 {
 Serial.println("Less than a feet distance object is placed can I take reverse"); 
 if(state == 'OK' || state == 'ok' || state == 'Ok' || state == 'oK')
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }
 }
 
}
 
