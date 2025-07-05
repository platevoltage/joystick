#include "HID-Project.h"

// Buttons
#define BUTTON_PIN_0 1
#define BUTTON_PIN_1 0
#define BUTTON_PIN_2 2
#define BUTTON_PIN_3 3
#define BUTTON_PIN_4 4
#define BUTTON_PIN_5 5
#define BUTTON_PIN_6 6
#define BUTTON_PIN_7 7
#define BUTTON_PIN_8 8
#define BUTTON_PIN_9 9

#define NUM_BUTTONS 10

const uint8_t buttonPins[NUM_BUTTONS] = {
    BUTTON_PIN_0, BUTTON_PIN_1, BUTTON_PIN_2, BUTTON_PIN_3, BUTTON_PIN_4,
    BUTTON_PIN_5, BUTTON_PIN_6, BUTTON_PIN_7, BUTTON_PIN_8, BUTTON_PIN_9};

#define L2_PIN 10
#define R2_PIN 14

// D-pad
#define DPAD_PIN_UP A0
#define DPAD_PIN_DOWN A1
#define DPAD_PIN_LEFT A2
#define DPAD_PIN_RIGHT A3

void setup() {

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(L2_PIN, INPUT_PULLUP);
  pinMode(R2_PIN, INPUT_PULLUP);

  pinMode(DPAD_PIN_UP, INPUT_PULLUP);
  pinMode(DPAD_PIN_DOWN, INPUT_PULLUP);
  pinMode(DPAD_PIN_LEFT, INPUT_PULLUP);
  pinMode(DPAD_PIN_RIGHT, INPUT_PULLUP);

  Gamepad.begin();
}

void probeButton(uint8_t buttonPin, uint8_t buttonNumber) {
  if (!digitalRead(buttonPin))
    Gamepad.press(buttonNumber);
  else
    Gamepad.release(buttonNumber);
}

void probeDpad() {
  // D-pad logic
  bool up = !digitalRead(DPAD_PIN_UP);
  bool down = !digitalRead(DPAD_PIN_DOWN);
  bool left = !digitalRead(DPAD_PIN_LEFT);
  bool right = !digitalRead(DPAD_PIN_RIGHT);

  uint8_t dpad = GAMEPAD_DPAD_CENTERED;
  if (up && left)
    dpad = GAMEPAD_DPAD_UP_LEFT;
  else if (up && right)
    dpad = GAMEPAD_DPAD_UP_RIGHT;
  else if (down && left)
    dpad = GAMEPAD_DPAD_DOWN_LEFT;
  else if (down && right)
    dpad = GAMEPAD_DPAD_DOWN_RIGHT;
  else if (up)
    dpad = GAMEPAD_DPAD_UP;
  else if (down)
    dpad = GAMEPAD_DPAD_DOWN;
  else if (left)
    dpad = GAMEPAD_DPAD_LEFT;
  else if (right)
    dpad = GAMEPAD_DPAD_RIGHT;

  Gamepad.dPad1(dpad);
}

void probeTriggers() {
  if (!digitalRead(R2_PIN))
    Gamepad.rzAxis(127);
  else
    Gamepad.rzAxis(-128);

  if (!digitalRead(L2_PIN))
    Gamepad.zAxis(127);
  else
    Gamepad.zAxis(-128);
}

void loop() {

  for (int i = 0; i < NUM_BUTTONS; i++) {
    probeButton(buttonPins[i], i + 1);
  }

  probeDpad();

  probeTriggers();

  Gamepad.write();
  // delay(5);
}
