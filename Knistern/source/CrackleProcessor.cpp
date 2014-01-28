#include "CrackleProcessor.h"

CrackleProcessor::CrackleProcessor()
	: sampleRate(0), crackleDepth(0)
{
}

void CrackleProcessor::initialize(float sampleRate) {
	this->sampleRate = sampleRate;

	float* crackleSamples = new float[10];
	crackleSamples[0] = 0.0;
	crackleSamples[1] = 0.1;
	crackleSamples[2] = 0.2;
	crackleSamples[3] = 0.5;
	crackleSamples[4] = 1.0;
	crackleSamples[5] = 0.7;
	crackleSamples[6] = 0.4; 
	crackleSamples[7] = -0.3;
	crackleSamples[8] = -0.1;
	crackleSamples[9] = 0.0;

	float* popSamples = new float[10];
	popSamples[0] = 0.1;
	popSamples[1] = 0.2;
	popSamples[2] = 0.3;
	popSamples[3] = 0.5;
	popSamples[4] = 0.8;
	popSamples[5] = 0.7;
	popSamples[6] = 0.4; 
	popSamples[7] = 0.2;
	popSamples[8] = -0.1;
	popSamples[9] = 0.0;

	crackle.initialize(crackleSamples, 10, 140); // Knistern
	pop.initialize(popSamples, 10, 1000);        // Knacken
}

void CrackleProcessor::setCrackleAmount(float amount) {
	crackle.setAmount(amount);
}

void CrackleProcessor::setCrackleDepth(float depth) {
	crackleDepth = depth;
}


float CrackleProcessor::processOneSample(float sample) {
	float crackleValue = crackle.getValue() * crackleDepth; // Depth beschreibt im Prinzip Lautstärke
	float popValue = pop.getValue();
	float processedSample =  crackleValue + popValue + sample;

	if(processedSample > 1.0) {
		processedSample = 1.0; // prevent clipping
	}
	else if (processedSample < -1.0 ) {
		processedSample = -1.0; // prevent clipping
	}

	return processedSample; 
}

void CrackleProcessor::process(float* input, float* output, int numberOfSamples) {
	for(int i = 0; i < numberOfSamples; i++) {
		output[i] = processOneSample(input[i]);
	}
}
