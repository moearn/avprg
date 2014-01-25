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
	void setWear(float wear);

	void setHissDepth(float depth);
	void setVibratoFrequency(float depth);
	void setVibratoDepth(float depth);
	void setCrackleDepth(float depth);
	void setCrackleAmount(float amount);
	void setHumHighFrequency(float freq);
	void setHumMidFrequency(float freq);
	void setHumHighDepth(float depth);
	void setHumMidDepth(float depth);
	void setHumVolume(float vol);

private:
	float sampleRate;
	float previousSample;
	float wearAmount; // (Verschleiﬂ)
	float gain;
	VibratoProcessor vibrato;
	HumProcessor hum;
	CrackleProcessor crackle;
	RauschProcessor hiss;
};
#endif