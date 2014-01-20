#ifndef CrackleProcessor_H
#define CrackleProcessor_H

#include "CrackleGenerator.h"

// Diese Klasse später durch Vinyl Processor ersetzen
// Dort alle Generatoren reinplatzieren (knistern, rauschen, vibrato usw)

class CrackleProcessor{
public:
	CrackleProcessor();
	~CrackleProcessor();
	void setCrackleAmount(float amount);
	void setCrackleDepth(float depth);
	void initialize(float sampleRate);
	float processOneSample(float sample);
	void process(float* input, float* output, int numberOfSamples);
private:
	float sampleRate;
	float crackleDepth;
	CrackleGenerator cg;
};

#endif