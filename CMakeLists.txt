cmake_minimum_required(VERSION 3.3)
project(CS327Project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES mains/main.cpp iSound.cpp headers/iSound.h soundFile.cpp headers/soundFile.h sndInfo.cpp headers/sndInfo.h)
#add_executable(CS327Project4 ${SOURCE_FILES})

set(sndinfo_files SoundFile.cpp headers/SoundFile.h IService.cpp headers/IService.h Service.cpp
        headers/Service.h InfoService.cpp headers/InfoService.h SampleLine.cpp headers/SampleLine.h similarMain.cpp)
add_executable(sndinfo ${sndinfo_files})

set(sndcat_files SoundFile.cpp headers/SoundFile.h IService.cpp headers/IService.h Service.cpp headers/Service.h
        ConcatService.cpp headers/ConcatService.h SampleLine.cpp headers/SampleLine.h similarMain.cpp)
add_executable(sndcat ${sndcat_files})

set(sndmix_files SoundFile.cpp headers/SoundFile.h IService.cpp headers/IService.h Service.cpp
        headers/Service.h SampleLine.cpp headers/SampleLine.h MixService.cpp headers/MixService.h similarMain.cpp)
add_executable(sndmix ${sndmix_files})

set(sndgen_files SoundFile.cpp headers/SoundFile.h similarMain.cpp sndgenMain.cpp)
add_executable(sndgen ${sndgen_files})

set(sndcvt_files similarMain.cpp)
add_executable(sndcvt ${sndcvt_files})

set(sndfx_files similarMain.cpp sndfxMain.cpp)
add_executable(sndfx ${sndfx_files})

set(sndplay_files similarMain.cpp sndplayMain.cpp)
add_executable(sndplay ${sndplay_files})