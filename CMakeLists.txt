cmake_minimum_required(VERSION 3.3)
project(CS327Project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES mains/main.cpp ISound.cpp headers/ISound.h SoundFile.cpp headers/SoundFile.h SndInfo.cpp headers/SndInfo.h)
#add_executable(CS327Project4 ${SOURCE_FILES})

set(sndinfo_files ISound.cpp headers/ISound.h mains/sndinfoMain.cpp SoundFile.cpp headers/SoundFile.h
        SndInfo.cpp headers/SndInfo.h)
add_executable(sndinfo ${sndinfo_files})

set(sndcat_files mains/sndcatMain.cpp sndcat.cpp sndcat.h SoundFile.cpp headers/SoundFile.h)
add_executable(sndcat ${sndcat_files})

set(sndmix_files mains/sndmixMain.cpp SoundFile.cpp headers/SoundFile.h)
add_executable(sndmix ${sndmix_files})

set(sndgen_files mains/sndgenMain.cpp SoundFile.cpp headers/SoundFile.h)
add_executable(sndgen ${sndgen_files})