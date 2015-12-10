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

Utility functions:
Utils.cpp - contains command line argument handling for sndinfo, sndcat, sndmix, and sndcvt. Also has helper messages functions.

Main methods:
similarMain.cpp - combined main method for sndinfo, sndcat, sndmix, and sndcvt
sndgenMain.cpp - main method for the sndgen program
sndfxMain.cpp - main method for the sndfx program
