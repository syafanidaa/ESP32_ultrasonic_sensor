#define triggerPin  26 // set Trigger ke pin 26/IO26
#define echoPin     25 // set Echo ke pin 25/IO25
#define pinLED  5 
int kondisi = 0;

void setup() {
  Serial.begin (115200);
  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode (pinLED, OUTPUT);


}
void loop() {
  long duration, jarak;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration / 2) / 29.1;
  Serial.println("jarak :");
  Serial.print(jarak);
  Serial.println(" cm");
  delay(1000);

  if (jarak <=20 && kondisi == 0 )
  {
    digitalWrite (pinLED, HIGH);
    delay(250);
    digitalWrite (pinLED, LOW);
    delay(250);
    digitalWrite (pinLED, HIGH);
    delay(250);
    digitalWrite (pinLED, LOW);
    delay(250);
    kondisi = 1;

  }
  else {
    digitalWrite (pinLED, LOW);
    kondisi = 0;
    delay(250);


  }
}
