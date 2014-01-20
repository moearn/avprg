#include "CrackleProcessor.h"

CrackleProcessor::CrackleProcessor()
	: sampleRate(0), crackleDepth(1)
{
}

void CrackleProcessor::initialize(float sampleRate) {
	this->sampleRate = sampleRate;
	float sample[7];
	sample[0] = 0;
	sample[1] = 0.1;
	sample[2] = 0.5;
	sample[3] = 1;
	sample[4] = 0.9;
	sample[5] = 0.7;
	sample[6] = 0.4; 
	cg.initialize(sample, 7);
}

void CrackleProcessor::setCrackleAmount(float amount) {
	cg.setAmount(amount);
}


float CrackleProcessor::processOneSample(float sample) {
	float crackleValue = cg.getValue() * crackleDepth; // Depth beschreibt im Prinzip Lautstärke
	return crackleValue + sample; // crackle auf original addieren
}

void CrackleProcessor::process(float* input, float* output, int numberOfSamples) {
	for(int i = 0; i < numberOfSamples; i++) {
		output[i] = processOneSample(input[i]);
	}
}
