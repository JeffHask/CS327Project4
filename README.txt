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