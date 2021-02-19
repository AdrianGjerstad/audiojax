#include "../include/AudioCalculation.h"

#include <cmath>

double jax::calc::pitch2frequency(double pitch) {
  // f(x) = 2^((x-69)/12) * 440
  return std::pow(2, (pitch-69)/12) * 440;
}

double jax::calc::frequency2pitch(double frequency) {
  // Frequency not allowed to be zero or negative
  if(frequency <= 0) return 0;

  // f(x) = 12*log2(x/440) + 69
  return std::log2(frequency/440)*12 + 69;
}

double jax::calc::velocity2gain(double velocity) {
  // Velocity not allowed to be negative, but zero velocity
  // also results in 0 gain, so whatever.
  if(velocity <= 0) return 0;

  // f(x) = 2^((20*log10(x/127))/3)
  return std::pow(2, (std::log10(velocity/127)*20)/3);
}

double jax::calc::gain2velocity(double gain) {
  // Gain not allowed to be negative, and zero gain also
  // maps to zero velocity.
  if(gain <= 0) return 0;

  // If I really wanted to be MIDI compliant, I would also
  // add a check to make sure gain wasn't larger than 127,
  // but I'm also using doubles for all of this, so I think
  // I don't need to worry about it.
  
  // f(x) = 10^((3*log2(x))/40) * 127
  return std::pow(10, (std::log2(gain)*3)/40) * 127;
}

