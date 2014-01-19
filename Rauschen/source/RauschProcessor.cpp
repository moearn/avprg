#include "RauschProcessor.h"

RauschProcessor::RauschProcessor()
: depth(0)
, sampleRate(0)
, buffer()
{
		setSweep(1);
        setDepth(DEPTH_DEFAULT_PERCENT / 100);
}

void RauschProcessor::initialize(float sampleRate){
        this->sampleRate = sampleRate;
        lfo.initialize(sampleRate);
        buffer.resize(DELAY_MAX_SEC * sampleRate);
}

void RauschProcessor::setSweep(float sweep){
		this->sweep = sweep;
}

void RauschProcessor::setDepth(float depth){
        this->depth = depth;
}

float RauschProcessor::processOneSample(float input){
		//generiert eine zufällige Frequenz zwischen 20 und 20.000 Hz
		float randomFreq = rand() % 19981 + 20;
		float oldFreq = buffer.readWithDelay(1);
		sweep *= (randomFreq / oldFreq);
		float output = (depth*randomFreq + input)*sweep;
        buffer.write(randomFreq);

        return output;
}
void RauschProcessor::process(float* input, float*output, int numberOfSamples){
        for(int i = 0; i < numberOfSamples; i++){
                output[i] = processOneSample(input[i]);
        }
}