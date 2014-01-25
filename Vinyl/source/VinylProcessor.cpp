#include "VinylProcessor.h"

VinylProcessor::VinylProcessor()
: gain(1)
{}

void VinylProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
}
void VinylProcessor::setGain(float gain){
	this->gain = gain;
}

float VinylProcessor::processOneSample(float input){
	return input * gain;
}
void VinylProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = crackle.processOneSample(input[i]) * 0.25 ;
	}
}