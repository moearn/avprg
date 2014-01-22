#include "HumProcessor.h"

HumProcessor::HumProcessor()
: volume(0.1)
{}

void HumProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	//lfo45Hz.initialize(sampleRate, 45);
	//lfo50Hz.initialize(sampleRate, 50);
	//lfo55Hz.initialize(sampleRate, 55);
	//lfo100Hz.initialize(sampleRate, 100);
	//lfo150Hz.initialize(sampleRate, 150);
	//lfo5000Hz.initialize(sampleRate, 5000);
	//lfo5050Hz.initialize(sampleRate, 5050);
	//lfo7050Hz.initialize(sampleRate, 7050);
	//lfo7100Hz.initialize(sampleRate, 7100);
	//lfo7150Hz.initialize(sampleRate, 7150);
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

	//float hum = lfo50Hz.getValue() * 0.40 + 
	//			lfo45Hz.getValue() * 0.05 + 
	//			lfo55Hz.getValue() * 0.05 +
	//			lfo100Hz.getValue() * 0.15 + 
	//			lfo150Hz.getValue() * 0.20 + 
	//			lfo5000Hz.getValue() * 0.003 +
	//			lfo5050Hz.getValue() * 0.002 +
	//			lfo7050Hz.getValue() * 0.003 +
	//			lfo7100Hz.getValue() * 0.003 +
	//			lfo7150Hz.getValue() * 0.003;

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