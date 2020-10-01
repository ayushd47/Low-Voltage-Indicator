int buzzer = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A2);
   Serial.println(sensorValue);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
  if (voltage < 3.25) {
    Serial.println("Red Light");
    Red();
    Buzer();
    delay(2000);
  }
  else if (voltage > 3.25 && voltage < 3.59) {
    Serial.println("Yellow Light");
    Yellow();
    delay(2000);
  }

  else if (voltage > 3.59 && voltage < 3.94) {
    Serial.println("Orange Light");
    Orange();
    delay(2000);
  }

  else {
    Serial.println("Green Light");
    Green();
    delay(2000);
  }
}

void Green() {

  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
  digitalWrite(13, LOW);
}
void Orange() {
  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(10, LOW);
  digitalWrite(2, LOW);
  digitalWrite(13, LOW);
}
void Yellow() {
  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}
void Red() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(2, LOW);
}
void Buzer() {
  tone(buzzer, 300, 100);
  delay(2000);

}
