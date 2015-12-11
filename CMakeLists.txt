cmake_minimum_required(VERSION 3.3)
project(CS327Project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES mains/main.cpp iSound.cpp headers/iSound.h soundFile.cpp headers/soundFile.h sndInfo.cpp headers/sndInfo.h)
#add_executable(CS327Project4 ${SOURCE_FILES})

set(sndinfo_files SoundFile.cpp headers/SoundFile.h Service.cpp ConcatService.cpp headers/ConcatService.h
        headers/Service.h InfoService.cpp headers/InfoService.h ConvertService.cpp headers/ConvertService.h SampleLine.cpp headers/SampleLine.h similarMain.cpp MixService.cpp headers/MixService.h Utils.cpp headers/Utils.h Sound.cpp headers/Sound.h)
add_executable(sndinfo ${sndinfo_files})

set(sndcat_files SoundFile.cpp headers/SoundFile.h  Service.cpp ConcatService.cpp headers/ConcatService.h
        headers/Service.h ConvertService.cpp headers/ConvertService.h InfoService.cpp headers/InfoService.h SampleLine.cpp headers/SampleLine.h similarMain.cpp MixService.cpp headers/MixService.h Utils.cpp headers/Utils.h Sound.cpp headers/Sound.h)
add_executable(sndcat ${sndcat_files})

set(sndmix_files SoundFile.cpp headers/SoundFile.h Service.cpp ConcatService.cpp headers/ConcatService.h
        headers/Service.h ConvertService.cpp headers/ConvertService.h InfoService.cpp headers/InfoService.h SampleLine.cpp headers/SampleLine.h similarMain.cpp MixService.cpp headers/MixService.h Utils.cpp headers/Utils.h Sound.cpp headers/Sound.h)
add_executable(sndmix ${sndmix_files})

set(sndgen_files SoundFile.cpp SampleLine.cpp headers/SampleLine.h headers/SoundFile.h Utils.cpp headers/Utils.h sndgenMain.cpp SoundGenerator.cpp headers/SoundGenerator.h Sound.cpp headers/Sound.h)
add_executable(sndgen ${sndgen_files})

set(sndcvt_files similarMain.cpp Utils.cpp headers/Utils.h SoundFile.cpp headers/SoundFile.h SampleLine.cpp
        headers/SampleLine.h ConvertService.cpp headers/ConvertService.h headers/InfoService.h InfoService.cpp headers/ConcatService.h ConcatService.cpp headers/MixService.h MixService.cpp Sound.cpp headers/Sound.h)
add_executable(sndcvt ${sndcvt_files})

set(sndfx_files SoundFile.cpp headers/SoundFile.h SampleLine.cpp headers/SampleLine.h sndfxMain.cpp Utils.cpp headers/Utils.h Sound.cpp headers/Sound.h EffectDecorator.cpp headers/EffectDecorator.h EchoDecorator.cpp headers/EchoDecorator.h  ShuffleDecorator.cpp headers/ShuffleDecorator.h SampleUpDecorator.cpp headers/SampleUpDecorator.h ReverseDecorator.cpp headers/ReverseDecorator.h SampleDownDecorator.cpp headers/SampleDownDecorator.h)
add_executable(sndfx ${sndfx_files})

set(sndplay_files sndplayMain.cpp Utils.cpp headers/Utils.h AbcFile.cpp headers/AbcFile.h AbcInstrument.cpp headers/AbcInstrument.h Note.cpp headers/Note.h SoundFile.cpp headers/SoundFile.h SoundGenerator.cpp headers/SoundGenerator.h SampleLine.cpp headers/SampleLine.h)
add_executable(sndplay ${sndplay_files})