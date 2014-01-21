#include "HumProcessor.h"

HumProcessor::HumProcessor()
: volume(0.1)
{}

void HumProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	lfo50Hz.initialize(sampleRate, 50);
	lfo100Hz.initialize(sampleRate, 100);
	lfo150Hz.initialize(sampleRate, 150);
	lfo500Hz.initialize(sampleRate, 500);
	lfo1000Hz.initialize(sampleRate, 1000);
	lfo2000Hz.initialize(sampleRate, 2000);
	lfo5000Hz.initialize(sampleRate, 5000);
}
void HumProcessor::setVolume(float vol){
	this->volume = vol;
}

float HumProcessor::processOneSample(float input){

	float hum = lfo50Hz.getValue() * 0.40 + 
				lfo100Hz.getValue() * 0.10 + 
				lfo150Hz.getValue() * 0.20 + 
				lfo500Hz.getValue() * 0.10 +
				lfo1000Hz.getValue() * 0.10 +
				lfo2000Hz.getValue() * 0.05 +
				lfo5000Hz.getValue() * 0.05;

	float processed = input + hum * volume;

	return processed;
}
void HumProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}