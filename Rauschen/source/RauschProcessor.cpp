#include "RauschProcessor.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

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
        buffer.resize(sampleRate);
}

void RauschProcessor::setSweep(float sweep){
		this->sweep = sweep;
}

void RauschProcessor::setDepth(float depth){
        this->depth = depth;
}

float RauschProcessor::processOneSample(float input){
		srand((unsigned)time(0));
		//generiert eine zufällige Frequenz zwischen 20 und 20.000 Hz
		float randomFreq = rand() % 20000 + 20;
		//aktuelle Frequenz wird in Buffer geschrieben
        buffer.write(randomFreq);
		//liest die ein Sample zuvor generierte Frequenz
		float oldFreq = buffer.readWithDelay(1);
		//generiert die neue Amplitude aus dem Quotient der beiden Frequenzen
		sweep *= (randomFreq / oldFreq);
		//output = stärke der Frequenz plus eingespieltes sample, sweep ist hier die amplitude
		float output = input + ((depth/2)*randomFreq)*sweep;

        return output;
}
void RauschProcessor::process(float* input, float*output, int numberOfSamples){
        for(int i = 0; i < numberOfSamples; i++){
                output[i] = processOneSample(input[i]);
        }
}