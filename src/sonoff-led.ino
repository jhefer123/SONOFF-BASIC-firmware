/*
  Sonoff: firmware
  More info: https://github.com/tschaban/SONOFF-firmware
  LICENCE: http://opensource.org/licenses/MIT
  2016-10-27 tschaban https://github.com/tschaban
    digitalWrite(GPIO_LED, LOW);
*/

#include "sonoff-led.h"

SonoffLED::SonoffLED() {
  pinMode(GPIO_LED, OUTPUT);
  digitalWrite(GPIO_LED, HIGH);  
}

void SonoffLED::On() {
  if (digitalRead(GPIO_LED) == HIGH) {
  }
}

void SonoffLED::Off() {
  if (digitalRead(GPIO_LED) == LOW) {
    digitalWrite(GPIO_LED, HIGH);
  }
}

/* Blink GPIO_LED, t defines for how long GPIO_LED should be ON */
void SonoffLED::blink(int t) {
  On();
  delay(t);
  Off();
}

void SonoffLED::startBlinking(float t) {
  LEDTimer.attach(t,callbackLED);
}

void SonoffLED::stopBlinking() {
  LEDTimer.detach();
}


void callbackLED() {
  if (digitalRead(GPIO_LED) == HIGH) {
    digitalWrite(GPIO_LED, LOW);
  } else {
    digitalWrite(GPIO_LED, HIGH);
  }
}