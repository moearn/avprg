#include "HumProcessor.h"

HumProcessor::HumProcessor()
: volume(0)
{}

void HumProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	mainsHum.initialize(sampleRate);
}
void HumProcessor::setVolume(float vol){
	this->volume = vol;
}

void HumProcessor::setMidFrequency(float freq){
	mainsHum.setMidFrequency(freq);
}

void HumProcessor::setHighFrequency(float freq){
	mainsHum.setHighFrequency(freq);
}

void HumProcessor::setMidDepth(float depth) {
	mainsHum.setMidAmount(depth);
}

void HumProcessor::setHighDepth(float depth) {
	mainsHum.setHighAmount(depth);
}

float HumProcessor::processOneSample(float input){

	float hum = mainsHum.getValue();
	float processed = input + hum * volume;
	processed = processed > 1.0 ? 1.0 : (processed < -1.0 ? -1.0 : processed); // prevent clipping

	return processed;
}


void HumProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}