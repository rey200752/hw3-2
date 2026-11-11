
const int ledPin = 3;
const int buttonPin = 2;

int mode = 0;
int lastButtonState = HIGH;

unsigned long previousMillis = 0;
unsigned long previousButtonMillis = 0;

int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(ledPin, LOW);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    if (millis() - previousButtonMillis > 200) {
      mode++;

      if (mode > 3) {
        mode = 0;
      }

      previousButtonMillis = millis();
      previousMillis = millis();
      ledState = LOW;
    }
  }

  lastButtonState = buttonState;

  if (mode == 0) {
    digitalWrite(ledPin, LOW);
  }
  else {
    int interval;

    if (mode == 1) {
      interval = 1000;
    }
    else if (mode == 2) {
      interval = 500;
    }
    else {
      interval = 200;
    }

    if (millis() - previousMillis >= interval) {
      previousMillis = millis();
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  }
}
