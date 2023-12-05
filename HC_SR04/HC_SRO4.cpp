#include "HC_SR04.h"
#include <Arduino.h>

UT::HC_SRO4::HC_SRO4(int trg, int echo) : trigger_pin(trg), echo_pin(echo) {
  pinMode(this->trigger_pin, OUTPUT);
  pinMode(this->echo_pin, INPUT);
}

[[nodiscard]] auto UT::HC_SRO4::get_distance() -> float {
  // Create The 10us pulse.
  digitalWrite(this->trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigger_pin, LOW);
  // Read the echo pin, to get the time the sound wave takes in us.
  this->duration = pulseIn(this->echo_pin, HIGH);
  // Calculate the distance.
  this->distance = (this->duration * 0.034) / 2;
  return distance;
}
