/*
Copyright (c) 2014-2021 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

// Software version
#define HID_PROJECT_VERSION 284

#if ARDUINO < 10607
#error HID Project requires Arduino IDE 1.6.7 or greater. Please update your IDE.
#endif

// #if !defined(USBCON)
// #error HID Project can only be used with an USB MCU.
// #endif

// Include all HID libraries (.a linkage required to work) properly
#include "MultiReport/AbsoluteMouse.h"
#include "MultiReport/Consumer.h"
#include "MultiReport/Gamepad.h"
#include "MultiReport/ImprovedKeyboard.h"
#include "MultiReport/ImprovedMouse.h"
#include "MultiReport/NKROKeyboard.h"
#include "MultiReport/SurfaceDial.h"
#include "MultiReport/System.h"
#include "SingleReport/BootKeyboard.h"
#include "SingleReport/BootMouse.h"
#include "SingleReport/RawHID.h"
#include "SingleReport/SingleAbsoluteMouse.h"
#include "SingleReport/SingleConsumer.h"
#include "SingleReport/SingleGamepad.h"
#include "SingleReport/SingleNKROKeyboard.h"
#include "SingleReport/SingleSystem.h"

// Include Teensy HID afterwards to overwrite key definitions if used
