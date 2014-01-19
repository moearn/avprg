#include "FlangerProcessor.h"


FlangerProcessor::FlangerProcessor()
: depth(0)
, sampleRate(0)
, buffer()
{
        setFrequency(FREQUENCY_DEFAULT_HZ);
        setDepth(DEPTH_DEFAULT_PERCENT / 100);
}

void FlangerProcessor::initialize(float sampleRate){
        this->sampleRate = sampleRate;
        lfo.initialize(sampleRate);
        buffer.resize(DELAY_MAX_SEC * sampleRate);
}
void FlangerProcessor::setFrequency(float frequency){
        lfo.setFrequency(frequency);
}

void FlangerProcessor::setDepth(float depth){
        this->depth = depth;
}

void FlangerProcessor::setSweepDepth(float sweepDepth){
		this->sweepDepth = sweepDepth;
}

void FlangerProcessor::setDelay(float delay){
		this->delay = delay;
}

float FlangerProcessor::processOneSample(float input){
        float lfoValue = lfo.getValue();                
		float lfoSweep = lfoValue * sweepDepth;
        int maxDelay = DELAY_MAX_SEC * sampleRate;
        
        float delay = lfoSweep * depth * maxDelay;
        float value = buffer.readWithDelay(delay);
        buffer.write(input);

        return value + input;
}
void FlangerProcessor::process(float* input, float*output, int numberOfSamples){
        for(int i = 0; i < numberOfSamples; i++){
                output[i] = processOneSample(input[i]);
        }
}