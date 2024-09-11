#pragma once
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <LedControl.h>
#include <Vector.h>

//Pins
const int xPin = A1;
const int yPin = A0;
const int SwitchPin = 9;
const int rs = 13, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int DataPin = 12;
const int CS = 11;
const int CLK = 10;

struct ivec2 {
  int x;
  int y;
};
template<typename T> void Verbose(T x) {
  //Serial.print(x);
};