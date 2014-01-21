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
	Lfo lfo45Hz;
	Lfo lfo50Hz;
	Lfo lfo55Hz;
	Lfo lfo100Hz;
	Lfo lfo150Hz;
	Lfo lfo5000Hz;
	Lfo lfo5050Hz;
	Lfo lfo7050Hz;
	Lfo lfo7100Hz;
	Lfo lfo7150Hz;

};
#endif