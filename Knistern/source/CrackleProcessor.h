#ifndef CrackleProcessor_H
#define CrackleProcessor_H

#include "Ringbuffer.h"
#include "CrackleGenerator.h"

// Diese Klasse später durch Vinyl Processor ersetzen
// Dort alle Generatoren reinplatzieren (knistern, rauschen, vibrato usw)

class CrackleProcessor{
public:
	CrackleProcessor();
	void setCrackleAmount(float amount);
	void initialize(float sampleRate);
	float processOneSample(float sample);
	void process(float* input, float* output, int numberOfSamples);
private:
	float sampleRate;
	float crackleDepth;
	CrackleGenerator cg;
};

#endif