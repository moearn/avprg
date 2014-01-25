#ifndef VINYL_PROCESSOR_H
#define VINYL_PROCESSOR_H

#include "..\..\Vibrato\source\VibratoProcessor.h"
#include "..\..\Netzbrummen\source\HumProcessor.h"
#include "..\..\Knistern\source\CrackleProcessor.h"
#include "..\..\Rauschen\source\RauschProcessor.h"


class VinylProcessor{
public:
	VinylProcessor();
	void initialize(float sampleRate);
	float processOneSample(float);
	void process(float* input, float*output, int numberOfSamples);
	void setGain(float gain);
private:
	float sampleRate;
	float gain;
	VibratoProcessor vibrato;
	HumProcessor hum;
	CrackleProcessor crackle;
	RauschProcessor rauschen;
};
#endif