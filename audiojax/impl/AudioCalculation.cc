#include "../include/AudioCalculation.h"

#include <cmath>

double jax::calc::pitch2frequency(double pitch) {
  // f(x) = 2^((x-69)/12) * 440
  return std::pow(2, (pitch-69)/12) * 440;
}

