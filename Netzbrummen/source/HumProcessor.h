#ifndef HUM_PROCESSOR_H
#define HUM_PROCESSOR_H

#include "HumGenerator.h"

class HumProcessor{
public:
	HumProcessor();
	void initialize(float sampleRate);
	float processOneSample(float);
	void process(float* input, float*output, int numberOfSamples);
	void setVolume(float volume);
	void setMidFrequency(float freq);
	void setHighFrequency(float freq);
	void setMidDepth(float depth);
	void setHighDepth(float depth);
private:
	float sampleRate;
	float volume;
	HumGenerator mainsHum;
};
#endif