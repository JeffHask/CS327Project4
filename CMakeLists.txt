cmake_minimum_required(VERSION 3.3)
project(CS327Project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES mains/main.cpp iSound.cpp headers/iSound.h soundFile.cpp headers/soundFile.h sndInfo.cpp headers/sndInfo.h)
#add_executable(CS327Project4 ${SOURCE_FILES})

set(sndinfo_files ISound.cpp headers/ISound.h mains/sndinfoMain.cpp SoundFile.cpp headers/SoundFile.h
        SndInfo.cpp headers/SndInfo.h)
add_executable(sndinfo ${sndinfo_files})

set(sndcat_files mains/sndcatMain.cpp SoundFile.cpp Sndcat.cpp
        headers/SoundFile.h headers/Sndcat.h mains/sndfxMain.cpp)
add_executable(sndcat ${sndcat_files})

set(sndmix_files mains/sndmixMain.cpp SoundFile.cpp
        headers/SoundFile.h headers/sndmix.h)
add_executable(sndmix ${sndmix_files})

set(sndgen_files mains/sndgenMain.cpp SoundFile.cpp headers/SoundFile.h headers/sndgen.h)
add_executable(sndgen ${sndgen_files})

set(sndcvt_files headers/sndcvt.h mains/sndcvtMain.cpp Sndcvt.cpp)
add_executable(sndcvt ${sndcvt_files})

set(sndfx_files headers/sndfx.h mains/sndfxMain.cpp Sndfx.cpp)
add_executable(sndfx ${sndfx_files})

set(sndplay_files headers/sndplay.h mains/sndplayMain.cpp Sndplay.cpp)
add_executable(sndplay ${sndplay_files})