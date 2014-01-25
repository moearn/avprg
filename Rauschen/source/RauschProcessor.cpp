#include "RauschProcessor.h"

RauschProcessor::RauschProcessor()
: depth(0)
, sampleRate(0)
, rauschen()
{
        setDepth(HISS_DEPTH_DEFAULT_PERCENT / 100);
}

void RauschProcessor::initialize(float sampleRate){
        this->sampleRate = sampleRate;
		this->rauschen = rauschen;
}

void RauschProcessor::setDepth(float depth){
        this->depth = depth;
}

float RauschProcessor::processOneSample(float input){
		float output = rauschen.generateOutput();
		return input + (output* depth* 0.1);
}
void RauschProcessor::process(float* input, float*output, int numberOfSamples){
        for(int i = 0; i < numberOfSamples; i++){
                output[i] = processOneSample(input[i]);
        }
}