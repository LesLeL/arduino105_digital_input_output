#define button1 D5
#define button2 D6
#define button3 D2
#define button4 D7
#define buzzer  D1
#define noteDis 311
#define noteFis 370
#define noteGis 415
#define noteAis 466

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  playTone(button1, noteDis);
  playTone(button2, noteFis);
  playTone(button3, noteGis);
  playTone(button4, noteAis);
}

void playTone(int buttonPin, int frequency) {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    tone(buzzer, frequency, 10);
  }
}
