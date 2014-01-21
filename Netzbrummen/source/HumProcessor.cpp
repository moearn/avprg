#include "HumProcessor.h"

HumProcessor::HumProcessor()
: hum(1)
{}

void HumProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	lfo.initialize(sampleRate);
}
void HumProcessor::setHum(float Hum){
	this->hum = hum;
}
void HumProcessor::setFrequency(float frequency) {
	lfo.setFrequency(frequency);
}
void HumProcessor::setTremoloDepth(float depth) {
	trem_depth = depth;
}
void HumProcessor::setTremoloOffset(float offset) {
	trem_offset = offset;
}

float HumProcessor::processOneSample(float input){
	float lfoValue = lfo.getValue();

	hum = trem_offset + lfoValue * trem_depth;

	return input * Hum;
}
void HumProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}