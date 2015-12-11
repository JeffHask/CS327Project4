programs: sndinfo sndcat sndmix sndgen sndfx sndplay

sndinfo :similarMain.cpp SoundFile.o ConcatService.o util.o SoundFile.o SampleLine.o InfoService.o MixService.o
	g++ -std=c++11 -o sndinfo similarMain.cpp SoundFile.o ConcatService.o util.o SampleLine.o InfoService.o MixService.o
sndcat :similarMain.cpp SoundFile.o util.o SampleLine.o ConcatService.o InfoService.o MixService.o
	g++ -std=c++11 -o sndcat similarMain.cpp SoundFile.o ConcatService.o util.o InfoService.o SampleLine.o MixService.o
sndmix : similarMain.cpp SoundFile.o util.o ConcatService.o MixService.o InfoService.o SampleLine.o
	g++ -std=c++11 -o sndmix util.o similarMain.cpp SoundFile.o ConcatService.o InfoService.o SampleLine.o MixService.o
sndgen : sndgenMain.cpp soundGen.o SoundFile.o util.o SampleLine.o
	g++ -std=c++11 -o sndgen sndgenMain.cpp SoundFile.o soundGen.o util.o SampleLine.o
sndfx : sndfxMain.cpp util.o SoundFile.o effect.o echo.o shuffle.o reverse.o upSample.o downSample.o SampleLine.o
	g++ -std=c++11 -o sndfx sndfxMain.cpp util.o SoundFile.o SampleLine.o echo.o effect.o shuffle.o reverse.o upSample.o downSample.o soundGen.o
sndplay : sndplayMain.cpp util.o soundGen.o Abcfile.o SoundFile.o SampleLine.o instrument.o note.o
	g++ -std=c++11 -o sndplay sndplayMain.cpp  util.o  soundGen.o Abcfile.o SoundFile.o SampleLine.o instrument.o note.o
ConcatService.o : headers/ConcatService.h ConcatService.cpp
	g++ -std=c++11 -c ConcatService.cpp
InfoService.o :headers/InfoService.h InfoService.cpp
	g++ -std=c++11 -c InfoService.cpp
MixService.o:headers/MixService.h MixService.cpp
	g++ -std=c++11 -c MixService.cpp
SoundFile.o : headers/SoundFile.h SoundFile.cpp
	g++ -std=c++11 -c SoundFile.cpp
SampleLine.o : headers/SampleLine.h SampleLine.cpp
	g++ -std=c++11 -c SampleLine.cpp
Abcfile.o : headers/AbcFile.h AbcFile.cpp
	g++ -std=c++11 -o Abcfile.o -c AbcFile.cpp
instrument.o:headers/AbcInstrument.h AbcInstrument.cpp
	g++ -std=c++11 -o instrument.o -c AbcInstrument.cpp
note.o: headers/Note.h Note.cpp
	g++ -std=c++11 -o note.o -c Note.cpp
effect.o : headers/EffectDecorator.h EffectDecorator.cpp
	g++ -std=c++11 -o effect.o -c EffectDecorator.cpp
echo.o : headers/EchoDecorator.h EchoDecorator.cpp
	g++ -std=c++11 -o echo.o -c EchoDecorator.cpp
shuffle.o : headers/ShuffleDecorator.h ShuffleDecorator.cpp
	g++ -std=c++11 -o shuffle.o -c ShuffleDecorator.cpp
reverse.o : headers/ReverseDecorator.h ReverseDecorator.cpp
	g++ -std=c++11 -o reverse.o -c ReverseDecorator.cpp
upSample.o : headers/SampleUpDecorator.h SampleUpDecorator.cpp
	g++ -std=c++11 -o upSample.o -c SampleUpDecorator.cpp
downSample.o : headers/SampleDownDecorator.h SampleDownDecorator.cpp
	g++ -std=c++11 -o downSample.o -c SampleDownDecorator.cpp
util.o : headers/Utils.h Utils.cpp
	g++ -std=c++11 -o util.o -c Utils.cpp

soundGen.o: SoundGenerator.cpp headers/SoundGenerator.h
	g++ -std=c++11 -o soundGen.o -c SoundGenerator.cpp

clean:
	rm sndinfo sndcat sndmix sndgen sndfx sndplay util.o soundGen.o ConcatService.o InfoService.o MixService.o SampleLine.o Abcfile.o instrument.o note.o effect.o echo.o shuffle.o reverse.o upSample.o downSample.o SoundFile.o 
