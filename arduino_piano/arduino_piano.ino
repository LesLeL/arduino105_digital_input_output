//Input/output pin definitions
#define button1 D2
#define button2 D5
#define button3 D6
#define button4 D7
#define buzzer  D1

// Notes to be played by buzzer in Hz
#define noteDis 311
#define noteFis 370
#define noteGis 415
#define noteAis 466

void setup() {
  pinMode(button1, INPUT_PULLUP); //Buttons are using INPUT_PULLUP mode 
  pinMode(button2, INPUT_PULLUP); //to avoid using additional resistors.
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

/*
 * Checks state of button connected to given pin
 * and plays back tone of selected frequency (in Hz)
 * as long as button is pressed
 */
void playTone(int buttonPin, int frequency) {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    //If button is pressed play given tone, 
    //stopping almost immediately (10ms) after button is released
    tone(buzzer, frequency, 10);
  }
}
