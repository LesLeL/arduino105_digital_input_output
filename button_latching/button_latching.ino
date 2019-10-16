#define button1 D5
#define button2 D6
#define button3 D7
#define led1    D1
#define led2    D2
#define led3    D3

int button1PushCounter = 0;
int button1PreviousState = 0;

int button2PushCounter = 0;
int button2PreviousState = 0;

int button3PushCounter = 0;
int button3PreviousState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  checkButtonState(button1, button1PushCounter, button1PreviousState, led1);
  checkButtonState(button2, button2PushCounter, button2PreviousState, led2);
  checkButtonState(button3, button3PushCounter, button3PreviousState, led3);
}

void checkButtonState(int buttonPin, 
        int &buttonPushCounter, 
        int &buttonPreviousState, 
        int ledPin) {
          
  int buttonState = digitalRead(buttonPin);

  if (buttonState != buttonPreviousState) {
    if (buttonState == LOW) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("Number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");
    }
    delay(50);
  }

  buttonPreviousState = buttonState;

  if (buttonPushCounter % 2 == 0) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
