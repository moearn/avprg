#include "CrackleProcessor.h"

CrackleProcessor::CrackleProcessor()
	: sampleRate(0), delay(0), minDelay(0)
{
}

void CrackleProcessor::initialize(float sampleRate) {
	this->sampleRate = sampleRate;
	cg.initialize({ 0, 0.1, 0.5, 1, 0.9, 0.7, 0.4 }, 7);
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
