#ifndef HUM_PROCESSOR_H
#define HUM_PROCESSOR_H
#include "Lfo.h"

class HumProcessor{
public:
	HumProcessor();
	void initialize(float sampleRate);
	float processOneSample(float);
	void process(float* input, float*output, int numberOfSamples);
	void setVolume(float volume);
private:
	float sampleRate;
	float volume;
	Lfo lfo50Hz;
	Lfo lfo100Hz;
	Lfo lfo150Hz;
	Lfo lfo500Hz;
	Lfo lfo1000Hz;
	Lfo lfo2000Hz;
	Lfo lfo5000Hz;
};
#endif