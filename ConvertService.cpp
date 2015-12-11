////
//// Created by jeffrey on 12/4/15.
////
//
//#include "headers/ConvertService.h"
//#include "headers/Utils.h"
//
//ConvertService::ConvertService(int help, string fileName, string outputFileName) {
//    this->help = help;
//    isWav = fileName.find(".wav") != string::npos ? 1 : 0;
//    this->outputFileName = outputFileName;
//    this->inputFileName = fileName;
//}
//
//void ConvertService::run() {
//    SoundFile * soundFile;
//    if(help) {
//        helperMessage();
//    } else {
//        if(isWav) {
//            soundFile = new SoundFile(inputFileName,1);
//            soundFile->writeCS229File(outputFileName);
//        } else {
//            soundFile = new SoundFile(inputFileName,0);
//            soundFile->writeWAVFile(outputFileName);
//        }
//    }
//}
//
//void ConvertService::helperMessage() {
////    TODO
//    h_helperMessage();
//}