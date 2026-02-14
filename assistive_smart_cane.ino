void setup() {
  pinMode(3, OUTPUT);   // TRIG of HC-SR04
  pinMode(4, INPUT);    // ECHO of HC-SR04
  pinMode(6, OUTPUT);   // vibration motor
  pinMode(7, OUTPUT);   // LED
}

void loop() {
  // 1. Send ultrasonic pulse
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  // 2. Read echo
  long duration = pulseIn(4, HIGH);
  int distance = duration * 0.034 / 2;

  // 3. Control LED and vibration motor
  if (distance < 50) {        // if object is closer than 50 cm
    digitalWrite(7, HIGH);    // turn LED ON
    digitalWrite(6, HIGH);    // turn vibration motor ON
  } else {
    digitalWrite(7, LOW);     // turn LED OFF
    digitalWrite(6, LOW);     // turn vibration motor OFF
  }

  delay(100); // wait 0.1 sec and repeat
}