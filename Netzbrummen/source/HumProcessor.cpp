#include "HumProcessor.h"

HumProcessor::HumProcessor()
: volume(0.1)
{}

void HumProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	lfo45Hz.initialize(sampleRate, 45);
	lfo50Hz.initialize(sampleRate, 50);
	lfo55Hz.initialize(sampleRate, 55);
	lfo100Hz.initialize(sampleRate, 100);
	lfo150Hz.initialize(sampleRate, 150);
	lfo5000Hz.initialize(sampleRate, 5000);
	lfo5050Hz.initialize(sampleRate, 5050);
	lfo7050Hz.initialize(sampleRate, 7050);
	lfo7100Hz.initialize(sampleRate, 7100);
	lfo7150Hz.initialize(sampleRate, 7150);
}
void HumProcessor::setVolume(float vol){
	this->volume = vol;
}

float HumProcessor::processOneSample(float input){

	float hum = lfo50Hz.getValue() * 0.50 + 
				lfo45Hz.getValue() * 0.05 + 
				lfo55Hz.getValue() * 0.05 +
				lfo100Hz.getValue() * 0.10 + 
				lfo150Hz.getValue() * 0.25 + 
				lfo5000Hz.getValue() * 0.003 +
				lfo5050Hz.getValue() * 0.002 +
				lfo7050Hz.getValue() * 0.005 +
				lfo7100Hz.getValue() * 0.005 +
				lfo7150Hz.getValue() * 0.005;

	float processed = input + hum * volume;

	return processed;
}
void HumProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}