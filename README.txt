CS229 Project 4: Fun with Sound Files
Classes:
SoundFile.cpp - data class that holds info about cs229 or wav files
SampleLine.cpp - data class that holds a single line of sample data
Service.cpp - Abstract class for Info,Concat,Mix, and Convert Service
InfoService.cpp - Class that handles the sndinfo program
ConcatService.cpp - Class that handles the sndcat program
MixService.cpp - Class that handles the sndMix program
ConvertService.cpp - Class that handles the sndCvt program
SoundGenerator.cpp - Class that handles the sndgen program
Sound.cpp - Interface class for SoundFile and EffectDecorator
EffectDecorator.cpp - Abstract Decorator for sndfx
EchoDecorator.cpp - Concrete Decorator for sndfx
ReverseDecorator.cpp - Concrete Decorator for sndfx
SampleDownDecorator.cpp - Concrete Decorator for sndfx
SampleUpDecorator.cpp - Concrete Decorator for sndfx
ShuffleDecorator.cpp - Concrete Decorator for sndfx
AbcFile.cpp - main file for sndplay, it contains all the information about a single abc229 file, while delegating some of that
information to other data objects
AbcInstrument.cpp - a data used in conjunction with AbcFile to store needed information. This helped make the AbcFile cleaner.
Note.cpp - another data class for sndplay. This contains a single note's frequency and the count it was assigned.
Utility functions:
Utils.cpp - contains command line argument handling for sndinfo, sndcat, sndmix, and sndcvt. Also has helper messages functions.

Main methods:
similarMain.cpp - combined main method for sndinfo, sndcat, sndmix, and sndcvt
sndgenMain.cpp - main method for the sndgen program
sndfxMain.cpp - main method for the sndfx program

OO patterns I implemented in this project:
Decorator pattern for sndfx. It has an interface of Sound, a concrete object that is soundfile, the abstract decorator
that is EffectDecorator, and the concrete decorators Shuffle,SampleUp,SampleDown,Reverse,Echo

Builder pattern for sound generator. With all of the different switches, I set the Soundbuilder with default values. It
worked really nicely, I don't have to create a giant constructor every time I wanted to use the SoundGenerator. I ended
up using it for sndplay, and being able to set and 'build' a new sound generator easily make my like a lot easier.

sndinfo: this program reads files either passed in, or it will read one file from standard input. If the file is read
from standard input, the file name will be set to 'From Standard Input'. There is nothing too crazy about this program,
mostly is just there to make sure if the file parsing is working properly.

sndcat: this program will read files passed in, and concatenate the files together. Errors will be thrown if the files
sampleRate, bit depth, or number of channels are not the same.

sndmix: This program reads files passes in, multiplies the files by their multiplier supplied alongside the file name,
then adds the samples together. If the other files have more samples than the first file, the additional samples will be
added to the sound file. Errors are thrown if all the file's sampleRate, bit depth, and number of channels are not the
same.

sndgen: This program creates a sound file based on a mess of switches. If switches are not specified, default values will
be placed. This program is built around using the builder pattern, and benefits from its uses. When dealing with frequency
and long release time, the samples have a chance to be all zeros. Sine, Sawtooth, and Triangle waves use math equations,
while pulse wave just uses a simple loop through, which can cause some off by one errors

sndfx: This program adds cool stuff to an individual file. I implemented a very interesting way of doing echo, a shuffle,
which uses time to randomly order the samples. I also made a up sampler and down sampler which scales samples up and down.
The last one I implemented is a reverse, which reverses the samples order

sndplay: This program is pretty cool. It can create some great sound, but it can have issues with release time, as the envelop
is for each individual note, so it is fairly easy to pick a high enough release time that it cause all values to be set to 0.
