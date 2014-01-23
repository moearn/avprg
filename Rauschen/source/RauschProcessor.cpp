#include "RauschProcessor.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

RauschProcessor::RauschProcessor()
: depth(0)
, sampleRate(0)
, buffer()
{
        setDepth(DEPTH_DEFAULT_PERCENT / 100);
}

void RauschProcessor::initialize(float sampleRate){
        this->sampleRate = sampleRate;
        buffer.resize(sampleRate);
		srand(time(NULL));
}


void RauschProcessor::setDepth(float depth){
        this->depth = depth;
}

float RauschProcessor::processOneSample(float input){
		float* arrayA = new float[5];
		arrayA[0] = 3.8024;
		arrayA[1] = 2.9694;
		arrayA[2] = 2.5970;
		arrayA[3] = 3.0870;
		arrayA[4] = 3.4006;

		float* arraySum = new float[5];
		arraySum[0] = 0.00198;
		arraySum[1] = 0.01478;
		arraySum[2] = 0.06378;
		arraySum[3] = 0.23378;
		arraySum[4] = 0.91578;

		float output = 0.0;
		float random = static_cast <float>(rand()) / static_cast <float>(RAND_MAX);
		
		for(int i = 0; i<5; i++){
			if(random <= arraySum[i]){
				srand(time(NULL));
				float random2 = static_cast <float>(rand()) / static_cast <float>(RAND_MAX);
				output += 2* (random2 - 0.5) * arrayA[i];
			}
		}
		
		return input + (output * depth);
		/*srand((unsigned int)time(0));
		//generiert eine zufällige Frequenz zwischen 20 und 20.000 Hz
		float randomFreq = rand() % 20000 + 20;
		//aktuelle Frequenz wird in Buffer geschrieben
        buffer.write(randomFreq);
		//liest die ein Sample zuvor generierte Frequenz
		float oldFreq = buffer.readWithDelay(1);
		//generiert die neue Amplitude aus dem Quotient der beiden Frequenzen
		sweep *= (randomFreq / oldFreq);
		//output = stärke der Frequenz plus eingespieltes sample, sweep ist hier die amplitude
		float output = input + ((depth/2)*randomFreq)*sweep;*/
}
void RauschProcessor::process(float* input, float*output, int numberOfSamples){
        for(int i = 0; i < numberOfSamples; i++){
                output[i] = processOneSample(input[i]);
        }
}