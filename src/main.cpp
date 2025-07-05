#include "HID-Project.h"

// Buttons
const uint8_t buttonPin0 = 1;
const uint8_t buttonPin1 = 0;
const uint8_t buttonPin2 = 2;
const uint8_t buttonPin3 = 3;
const uint8_t buttonPin4 = 4;
const uint8_t buttonPin5 = 5;
const uint8_t buttonPin6 = 6;
const uint8_t buttonPin7 = 7;
const uint8_t buttonPin8 = 8;
const uint8_t buttonPin9 = 9; //
const uint8_t L2Pin = 10;     //
const uint8_t R2Pin = 14;     //
// const uint8_t buttonPin13 = 14;
// const uint8_t buttonPin14 = 15;
// const uint8_t buttonPin15 = 16;

// D-pad
const uint8_t dpadUpPin = A0;
const uint8_t dpadDownPin = A1;
const uint8_t dpadLeftPin = A2;
const uint8_t dpadRightPin = A3;

void setup() {
  pinMode(buttonPin0, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin9, INPUT_PULLUP);
  pinMode(L2Pin, INPUT_PULLUP);
  pinMode(R2Pin, INPUT_PULLUP);

  // pinMode(buttonPin13, INPUT_PULLUP);
  // pinMode(buttonPin14, INPUT_PULLUP);
  // pinMode(buttonPin15, INPUT_PULLUP);

  pinMode(dpadUpPin, INPUT_PULLUP);
  pinMode(dpadDownPin, INPUT_PULLUP);
  pinMode(dpadLeftPin, INPUT_PULLUP);
  pinMode(dpadRightPin, INPUT_PULLUP);

  Gamepad.begin();
}

void loop() {
  // Buttons 1–15
  if (!digitalRead(buttonPin0))
    Gamepad.press(1);
  else
    Gamepad.release(1);
  if (!digitalRead(buttonPin1))
    Gamepad.press(2);
  else
    Gamepad.release(2);
  if (!digitalRead(buttonPin2))
    Gamepad.press(3);
  else
    Gamepad.release(3);
  if (!digitalRead(buttonPin3))
    Gamepad.press(4);
  else
    Gamepad.release(4);
  if (!digitalRead(buttonPin4))
    Gamepad.press(5);
  else
    Gamepad.release(5);
  if (!digitalRead(buttonPin5))
    Gamepad.press(6);
  else
    Gamepad.release(6);
  if (!digitalRead(buttonPin6))
    Gamepad.press(7);
  else
    Gamepad.release(7);
  if (!digitalRead(buttonPin7))
    Gamepad.press(8);
  else
    Gamepad.release(8);
  if (!digitalRead(buttonPin8))
    Gamepad.press(9);
  else
    Gamepad.release(9);

  if (!digitalRead(buttonPin9))
    Gamepad.press(10);
  else
    Gamepad.release(10);

  if (!digitalRead(R2Pin))
    Gamepad.rzAxis(127);
  else
    Gamepad.rzAxis(-128);

  if (!digitalRead(L2Pin))
    Gamepad.zAxis(127);
  else
    Gamepad.zAxis(-128);

  // D-pad logic
  bool up = !digitalRead(dpadUpPin);
  bool down = !digitalRead(dpadDownPin);
  bool left = !digitalRead(dpadLeftPin);
  bool right = !digitalRead(dpadRightPin);

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

  Gamepad.write();
  // delay(5);
}
