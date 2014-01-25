#include "VinylProcessor.h"

VinylProcessor::VinylProcessor()
: gain(1), wearAmount(0.5)
{}

void VinylProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
}
void VinylProcessor::setGain(float gain){
	this->gain = gain;
}
void VinylProcessor::setWear(float wear) {
	this->wearAmount = wear;
}

void VinylProcessor::setCrackleAmount(float amount) {
	crackle.setCrackleAmount(amount);
}
void VinylProcessor::setCrackleDepth(float depth) {
	crackle.setCrackleDepth(depth);
}

void VinylProcessor::setVibratoFrequency(float freq) {
	vibrato.setFrequency(freq);
}
void VinylProcessor::setCrackleDepth(float depth) {
	vibrato.setDepth(depth);
}

void VinylProcessor::setHissDepth(float depth) {
	hiss.setDepth(depth);
}

void VinylProcessor::setHumHighFrequency(float freq){
	hum.setHighFrequency(freq);
}
void VinylProcessor::setHumMidFrequency(float freq){
	hum.setMidFrequency(freq);
}
void VinylProcessor::setHumHighDepth(float depth){
	hum.setHighDepth(depth);
}
void VinylProcessor::setHumMidDepth(float depth){
	hum.setMidDepth(depth);
}
void VinylProcessor::setHumVolume(float vol) {
	hum.setVolume(vol);
}

float VinylProcessor::processOneSample(float input){
	float currentSample = input;
	
	// chaining the signal -- (1. Crackle, 2. Vibrato, 3. Hiss, 4. LowPass-Filter, 5. Mainshum)
	currentSample = crackle.processOneSample(currentSample);
	currentSample = vibrato.processOneSample(currentSample);
	currentSample = hiss.processOneSample(currentSample);
	currentSample = wearAmount * previousSample + (1-wearAmount) * currentSample;
	currentSample = hum.processOneSample(currentSample);

	this->previousSample = currentSample;

	return currentSample;
}
void VinylProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}