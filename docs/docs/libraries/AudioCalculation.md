# AudioCalculation Documentation

**Header file**: [audiojax/include/AudioCalculation.h](https://github.com/AdrianGjerstad/audiojax/blob/main/audiojax/include/AudioCalculation.h)<br/>
**Source file**: [audiojax/impl/AudioCalculation.cc](https://github.com/AdrianGjerstad/audiojax/blob/main/audiojax/include/AudioCalculation.h)

---

## Overview

The `AudioCalculation` is a basic core library for AudioJAX, and is responsible for making simple (non-linear, logarithmic, exponential) calculations easier to perform and harder to mess up.

This library places its content inside the namespace `jax::calc`.

## Methods

<details open>
<summary>Table of Contents</summary>
<ul>
<li><a href="#double-jaxcalcpitch2frequencydouble-pitch"><code>double jax::calc::pitch2frequency(double pitch)</code></a></li>
<li><a href="#double-jaxcalcfrequency2pitchdouble-frequency"><code>double jax::calc::frequency2pitch(double frequency)</code></a></li>
<li><a href="#double-jaxcalcvelocity2gaindouble-velocity"><code>double jax::calc::velocity2gain(double velocity)</code></a></li>
<li><a href="#double-jaxcalcgain2velocitydouble-gain"><code>double jax::calc::gain2velocity(double gain)</code></a></li>
</ul>
</details>

---

### double jax::calc::pitch2frequency(double pitch)

| Parameter | Type | Description |
|-----------|------|-------------|
| `pitch` | `double` | The MIDI note to get a frequency for (may contain a fractional part) |

#### Return Value

This method returns a value of type `double`, portraying the frequency, in hertz, of the given MIDI note.

#### Description

One of the most important capabilities of a MIDI-enabled synth is the ability to take MIDI note values and convert them to frequencies which can then be used to forge the desired audio signal. This method enables a simple way to do that without messing it up.

In addition, notice the fact that the note is passed into this method as a double. This fact means that you can pass notes &plusmn; cents. For example, if you want Middle C (MIDI Pitch 60) plus five cents, just pass `60.05`, since 100 cents is equivalent to one semitone.

This calculation, along with all other methods and functionalities of the AudioJAX library assume a MIDI tuning of A<sub>4</sub> = 440 Hz.

> If you are interested, the definition of this method, along with a more readable, mathematic-oriented version can be found at its definition in the [source file](https://github.com/AdrianGjerstad/audiojax/blob/main/audiojax/impl/AudioCalculation.cc) (audiojax/impl/AudioCalculation.cc).

### double jax::calc::frequency2pitch(double frequency)

| Parameter | Type | Description |
|-----------|------|-------------|
| `frequency` | `double` | The frequency, in hertz, to get the corresponding MIDI note (with cents) with. |

#### Return Value

This method returns a value of type `double`, portraying a MIDI note-cent combination where cents have been divided by 100 and added to the MIDI note number, meaning an output of `59.83` actually means MIDI note 60 minus 17 cents.

#### Description

Arguably, this is a far less useful method in comparison to [`pitch2frequency`](#double-jaxcalcpitch2frequencydouble-pitch), but still has its uses in FFT data analysis, since FFTs only give frequency bands. For example, this could be used in a device that converts a raw audio signal into a MIDI signal, which can in turn be converted to a computer-generated tone.

Note that only positive, non-zero frequencies are allowed, and anything outside that range will result in a pitch of zero, however, in the future this behavior is planned to be changed to raise an exception, so check your inputs.

On the other hand, this method can a few one-time purposes, such as calculating the number of cents offset required to convert between 440 Hz and 432 Hz tunings. Note also that the conversion is done with A<sub>4</sub> = 440 Hz.

> If you are interested, the definition of this method, along with a more readable, mathematic-oriented version can be found at its definition in the [source file](https://github.com/AdrianGjerstad/audiojax/blob/main/audiojax/impl/AudioCalculation.cc) (audiojax/impl/AudioCalculation.cc).

### double jax::calc::velocity2gain(double velocity)

| Parameter | Type | Description |
|-----------|------|-------------|
| `velocity` | `double` | The MIDI velocity to convert to a gain multiplier. |

#### Return Value

This method returns the gain multiplier value (e.g. `0.5 = -6db`, `0.25 = -12db`, etc.) based on an input MIDI velocity, where a velocity of 127 results in a gain value of 1.

#### Description

In the context of a MIDI synthesizer or tone generator, it is hard to convert from a simple MIDI velocity to a usable multiplier to change the volume of the signal, since there is no widely agreed upon formula for doing so. Some DAWs implement this conversion as a simple linear mapping, and others exaggerate an exponential curve.

This implementation strikes a decent balance between the two, providing a good conversion from MIDI velocity to gain for every part of AudioJAX to utilizie.

Note that, if this method is given a negative value, a gain value of zero is returned because negative inputs to logarithms results in exceptions. This behavior may eventually be changed to raise an exception itself.

> If you are interested, the definition of this method, along with a more readable, mathematic-oriented version can be found at its definition in the [source file](https://github.com/AdrianGjerstad/audiojax/blob/main/audiojax/impl/AudioCalculation.cc) (audiojax/impl/AudioCalculation.cc).

### double jax::calc::gain2velocity(double gain)

| Parameter | Type | Description |
|-----------|------|-------------|
| `gain` | `double` | The gain value to convert to a MIDI velocity value. |

#### Return Value

This method returns the MIDI velocity version of a gain multiplier, where a gain of 1 is a velocity of 127.

#### Description

Like [`double jax::calc::frequency2pitch(double frequency)`](#double-jaxcalcfrequency2pitchdouble-frequency), this method may not be quite as useful, though it is still here to stay, as it may be necessary for various functionalities and/or other audio-midi units.

This implementation offers an inverse algorithm for conversion between MIDI velocity and gain multipliers. Its use is limited, however, could be used for calculating the volume of MIDI notes pulled from FFT data of original audio data.

Notice that, since a negative multiplier is (1) not possible given a velocity, and (2) just reverses and applies gain to an audio signal, negative inputs result in a velocity of zero.

> If you are interested, the definition of this method, along with a more readable, mathematic-oriented version can be found at its definition in the [source file](https://github.com/AdrianGjerstad/audiojax/blob/main/audiojax/impl/AudioCalculation.cc) (audiojax/impl/AudioCalculation.cc).

## Example

```cpp
#include "@adgjerstad_audiojax/audiojax/include/AudioCalculation.h"
#include <iostream>

int main(int argc, char** argv) {
  for(int i = 0; i < 128; ++i) {
    std::cout << "Note " << i << " - Frequency " << jax::calc::pitch2frequency(i) << std::endl;
  }
  
  return 0;
}

```

Example Output

```
Note 0 - Frequency 8.1758
Note 1 - Frequency 8.66196
Note 2 - Frequency 9.17702
Note 3 - Frequency 9.72272
Note 4 - Frequency 10.3009
Note 5 - Frequency 10.9134
Note 6 - Frequency 11.5623
Note 7 - Frequency 12.2499
Note 8 - Frequency 12.9783
Note 9 - Frequency 13.75
...
Note 64 - Frequency 329.628
Note 65 - Frequency 349.228
Note 66 - Frequency 369.994
Note 67 - Frequency 391.995
Note 68 - Frequency 415.305
Note 69 - Frequency 440
Note 70 - Frequency 466.164
Note 71 - Frequency 493.883
Note 72 - Frequency 523.251
Note 73 - Frequency 554.365
Note 74 - Frequency 587.33
Note 75 - Frequency 622.254
Note 76 - Frequency 659.255
Note 77 - Frequency 698.456
Note 78 - Frequency 739.989
...
```

> These frequencies are not the values the rest of your program sees, since the subroutine for printing `double`s omits decimal places after a certain point. Note 1 is a good example of this if you are skeptical.

## Licensing

This library, as it is a part of the AudioJAX framework, is licensed under the same license as AudioJAX, which, at the time of this introductory commit, is the Apache 2.0 license. Please open an issue if this is wrong.
