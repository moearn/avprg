#ifndef GAIN_PROCESSOR_H
#define GAIN_PROCESSOR_H
#include "Lfo.h"

class GainProcessor{
public:
	GainProcessor();
	void initialize(float sampleRate);
	float processOneSample(float);
	void process(float* input, float*output, int numberOfSamples);
	void setGain(float gain);
	void setFrequency(float frequency);
	void setTremoloOffset(float offset);
	void setTremoloDepth(float depth);
private:
	float sampleRate;
	float gain;
	float trem_offset;
	float trem_depth;
	Lfo lfo;
};
#endif