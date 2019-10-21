#define button1 D5
#define button2 D6
#define button3 D2
#define button4 D7
#define buzzer  D1

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  playTone(button1, 311);
  playTone(button2, 370);
  playTone(button3, 415);
  playTone(button4, 466);
}

void playTone(int buttonPin, int frequency) {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    tone(buzzer, frequency, 10);
  }
}
