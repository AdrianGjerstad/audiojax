# audiojax
A simple and expandable C++ Digital Signal Processing library.

## Notice

I apologize for this, but I wanted to get this information out as soon as possible.

Depending on when you see this, I have probably abandoned the project. If you truly want to see this project become something cool, do something that will trigger a notification on my end. Star the project, watch it, something.

If my last commit has been in the last week, don't bother, because I probably plan on adding something new soon.

## Purpose

So you may be asking yourself, like when you see any other libraries that have been done several times, "why?" The answer is quite simple: I want to be able to explore the world of DSP (Digital Signal Processing), and see what cool things I can come up with.

Through my several years so far of working with audio in various DAWs (Digital Audio Workstations), I have wondered about the math behind it all. What makes an amp simulation work? What about an EQ? How do FFTs (Fast Fourier Transforms) work?

To thoroughly explore what was possible, I created a small Python project that has since been demolished :cry:. The goal of this project was to build a few simple tone generators (sine, triangle, square, etc.), and put their output in a `.wav` file. I learned a lot more in the process than I thought I would; most notably, I learned the `.wav` file format/codec. If you want to learn about it, or reference it, here is an [*old*-looking webpage explaining it](http://soundfile.sapp.org/doc/WaveFormat/).

After this success, I wanted to learn about how some of the basic audio effects work, such as faders, which just scale the waveform by a given amount. Soon after figuring this out, I abandoned the project because I had made a number of mistakes, including, though not limited to:

1. Storing an entire 5 second audio buffer at 48kHz in RAM.
2. Using python for "fast" audio processing.

Of course the entire thing was just a proof-of-concept project. Since then, I have dabbled in other ways of interacting with audio using `C++`, all of which I, naturally, never saw to completion.

This time, since audio has become a large part of what I do during my day-to-day life, I have decided that I will make at least one commit every week, though this is just a baseline, of course. The problem with this is that I am just one person, and, without anybody counting on me to build such a project, I may lapse.

### Contributing

This is where you, the reader, come in. If you want to learn about audio processing just the way I did, star this repository. This way, I know that I'm not just investing wasted time in a project that I won't be using long time, even though I have a few ideas for this project.

If you have an idea, even if you think it is useless, open an issue and share it! I am far past my introduction to audio, and so I am not entirely sure how exactly to structure things. The same goes for questions; if you have one, ask it in the "Issues" section.

If and when you come up with ideas, see if you can't try something out and create a pull request. Remember that we can always tweak or add things to branches before we merge them, even if you have only started.

