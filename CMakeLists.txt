cmake_minimum_required(VERSION 3.3)
project(CS327Project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES mains/main.cpp iSound.cpp headers/iSound.h soundFile.cpp headers/soundFile.h sndInfo.cpp headers/sndInfo.h)
#add_executable(CS327Project4 ${SOURCE_FILES})

set(sndinfo_files mains/sndinfoMain.cpp SoundFile.cpp headers/SoundFile.h
        IService.cpp headers/IService.h Service.cpp headers/Service.h InfoService.cpp headers/InfoService.h)
add_executable(sndinfo ${sndinfo_files})

set(sndcat_files mains/sndcatMain.cpp SoundFile.cpp headers/SoundFile.h IService.cpp headers/IService.h Service.cpp headers/Service.h ConcatService.cpp headers/ConcatService.h)
add_executable(sndcat ${sndcat_files})

set(sndmix_files mains/sndmixMain.cpp SoundFile.cpp headers/SoundFile.h IService.cpp headers/IService.h Service.cpp headers/Service.h)
add_executable(sndmix ${sndmix_files})

set(sndgen_files mains/sndgenMain.cpp SoundFile.cpp headers/SoundFile.h)
add_executable(sndgen ${sndgen_files})

set(sndcvt_files mains/sndcvtMain.cpp)
add_executable(sndcvt ${sndcvt_files})

set(sndfx_files mains/sndfxMain.cpp)
add_executable(sndfx ${sndfx_files})

set(sndplay_files mains/sndplayMain.cpp)
add_executable(sndplay ${sndplay_files})