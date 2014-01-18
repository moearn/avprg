#include "VibratoProcessor.h"


VibratoProcessor::VibratoProcessor()
: depth(0)
, sampleRate(0)
{
	setFrequency(FREQUENCY_DEFAULT_HZ);
	setDepth(DEPTH_DEFAULT_PERCENT / 100);
}

void VibratoProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	lfo.initialize(sampleRate);
	buffer.resize(DELAY_MAX_SEC * sampleRate);
}
void VibratoProcessor::setFrequency(float frequency){
	lfo.setFrequency(frequency);
}

void VibratoProcessor::setDepth(float depth){
	this->depth = depth;
}

float VibratoProcessor::processOneSample(float input){
	float lfoValue = lfo.getValue();		

	int maxDelay = DELAY_MAX_SEC * sampleRate;
	
	float delay = lfoValue * depth * maxDelay;
	float value = buffer.readWithDelay(delay);
	buffer.write(input);

	return value;
}
void VibratoProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}