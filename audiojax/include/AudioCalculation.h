#ifndef AUDIOJAX_INCLUDE_AUDIOCALCULATION_H_
#define AUDIOJAX_INCLUDE_AUDIOCALCULATION_H_

namespace jax {

namespace calc {

double pitch2frequency(double pitch);
double frequency2pitch(double frequency);

double velocity2gain(double velocity);
double gain2velocity(double gain);

} // namespace calc

} // namespace jax

#endif  // AUDIOJAX_INCLUDE_AUDIOCALCULATION_H_

