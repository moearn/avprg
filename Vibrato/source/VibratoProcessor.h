#ifndef VIBRATO_PROCESSOR_H
#define VIBRATO_PROCESSOR_H

#include "..\..\common\Lfo.h"
#include "RingBuffer.h"


const float DELAY_MAX_SEC = 10.0 / 1000.0;	// max 10 ms Delay
const float VIBRATO_FREQUENCY_DEFAULT_HZ = 1;
const float VIBRATO_FREQUENCY_MAX_HZ = 14;
const float VIBRATO_DEPTH_DEFAULT_PERCENT = 50;


class VibratoProcessor{
public:
	VibratoProcessor();
	void initialize(float sampleRate);
	float processOneSample(float);
	void process(float* input, float*output, int numberOfSamples);
	void setFrequency(float frequency);
	void setDepth(float depth);
private:
	float sampleRate;
	Lfo lfo;
	RingBuffer buffer;
	float depth;
};
#endif