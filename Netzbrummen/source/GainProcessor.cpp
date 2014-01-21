#include "GainProcessor.h"

GainProcessor::GainProcessor()
: gain(1)
{}

void GainProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	lfo.initialize(sampleRate);
}
void GainProcessor::setGain(float gain){
	this->gain = gain;
}
void GainProcessor::setFrequency(float frequency) {
	lfo.setFrequency(frequency);
}
void GainProcessor::setTremoloDepth(float depth) {
	trem_depth = depth;
}
void GainProcessor::setTremoloOffset(float offset) {
	trem_offset = offset;
}

float GainProcessor::processOneSample(float input){
	float lfoValue = lfo.getValue();

	gain = trem_offset + lfoValue * trem_depth;

	return input * gain;
}
void GainProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}