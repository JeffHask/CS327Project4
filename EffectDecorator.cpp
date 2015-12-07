//
// Created by jeffrey on 12/5/15.
//

#include "headers/EffectDecorator.h"

EffectDecorator::EffectDecorator(Sound* soundFile) {
    this->soundFile = soundFile;
}

void EffectDecorator::print(string outputFile) {
    ((SoundFile *)soundFile)->print(outputFile);
}


void EffectDecorator::setSampleLine(int index, SampleLine *sampleLine) {
    ((SoundFile*)soundFile)->setSampleLine(index, sampleLine);
}

string EffectDecorator::getFileName() const {
    return ((SoundFile*)(soundFile))->getFileName();
}

void EffectDecorator::setFileName(char *fileName) {
    ((SoundFile*)(soundFile))->setFileName(fileName);
}

string EffectDecorator::getFileType() const {
    return ((SoundFile*)(soundFile))->getFileType();
}

int EffectDecorator::getSampleRate() const {
    return ((SoundFile*)(soundFile))->getSampleRate();
}

void EffectDecorator::setSampleRate(int sampleRate) {
    ((SoundFile*)soundFile)->setSampleRate(sampleRate);
}

int EffectDecorator::getBitDepth() const {
    return ((SoundFile*)(soundFile))->getBitDepth();
}

void EffectDecorator::setBitDepth(int bitDepth) {
    ((SoundFile*)(soundFile))->setBitDepth(bitDepth);
}

int EffectDecorator::getNumberOfChannels() const {
    return ((SoundFile*)(soundFile))->getNumberOfChannels();
}

void EffectDecorator::setNumberOfChannels(int numberOfChannels) {
    ((SoundFile*)(soundFile))->setNumberOfChannels(numberOfChannels);
}

vector<SampleLine*> EffectDecorator::getSamples() const {
    return ((SoundFile*)(soundFile))->getSamples();
}

void EffectDecorator::setSamples(vector<SampleLine*>samples) {
    ((SoundFile*)(soundFile))->setSamples(samples);
}

int EffectDecorator::getNumberOfSamples() const {
    return ((SoundFile*)(soundFile))->getNumberOfSamples();
}

void EffectDecorator::setNumberOfSamples(int numberOfSamples) {
    ((SoundFile*)(soundFile))->setNumberOfSamples(numberOfSamples);
}

void EffectDecorator::setFileType(const string &fileType) {
    ((SoundFile*)(soundFile))->setFileType(fileType);
}

void EffectDecorator::setFileName(const string &fileName) {
    ((SoundFile*)(soundFile))->setFileName(fileName);
}
