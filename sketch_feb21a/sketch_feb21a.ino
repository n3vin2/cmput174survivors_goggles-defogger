#include <Servo.h>

Servo myServoLeft;
Servo myServoRight;

int pos = 0;
int averageLight;

void setup() {
  // put your setup code here, to run once:
  myServoLeft.attach(7);
  myServoRight.attach(13);
  Serial.begin(9600);

  int n = 1000;
  unsigned long lightSum = 0;
  for (int i = 0; i < n; i++) {
    int val = analogRead(A0);
    lightSum += val;
    Serial.print(i);
    Serial.print(" ");
    Serial.print(val);
    Serial.print(" ");
    Serial.println(lightSum);
    delay(10);
  }

  averageLight = lightSum / n;
  Serial.print("FINAL AVERAGE: ");
  Serial.println(averageLight);
  //pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int value = analogRead(A0);
  Serial.println(value);
  if (value < averageLight) {
    for (pos = 0; pos <= 180; pos += 4) {
      myServoLeft.write(pos);
      myServoRight.write(pos);
      delay(10);
    }
    delay(150);
    for (pos = 180; pos >= 0; pos -= 4) {
      myServoLeft.write(pos);
      myServoRight.write(pos);
      delay(10);
    }
    delay(250);
  }
  delay(250);
}
