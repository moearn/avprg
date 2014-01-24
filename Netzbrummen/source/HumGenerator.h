#ifndef HUM_GENERATOR_H_
#define HUM_GENERATOR_H_

#include "Lfo.h"

class HumGenerator {
public:
	HumGenerator();
	void initialize(float sampleRate);
	void setBaseAmount(float amount);
	void setHighAmount(float amount);
	void setHighFrequency(float freq);
	void setHighClarity(float clarity);
	void setMidAmount(float amount);
	void setMidFrequency(float freq);
	void setMidClarity(float clarity);
	float getValue();
private:
	Lfo baseFreqLfos[3]; 
	Lfo highFreqLfos[6];
	Lfo midFreqLfos[3];
	float getBaseFreqValue();
	float getMidFreqValue();
	float getHighFreqValue();
	float baseAmount;
	float midAmount;
	float highAmount;
};


#endif