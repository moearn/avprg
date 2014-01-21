#ifndef HUM_PROCESSOR_H
#define HUM_PROCESSOR_H
#include "Lfo.h"

class HumProcessor{
public:
	HumProcessor();
	void initialize(float sampleRate);
	float processOneSample(float);
	void process(float* input, float*output, int numberOfSamples);
	void setHum(float hum);
	void setFrequency(float frequency);
	void setTremoloOffset(float offset);
	void setTremoloDepth(float depth);
private:
	float sampleRate;
	float hum;
	float trem_offset;
	float trem_depth;
	Lfo lfo;
};
#endif