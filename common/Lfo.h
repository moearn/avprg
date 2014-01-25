#ifndef LFO_H_
#define LFO_H_

class Lfo {
public:
	Lfo(void);
	~Lfo(void);
	void initialize(float sampleRate, float freq);
	void setFrequency(float freq);
	void setPhase(float phase);
	float getValue();
private:
	float sampleRate;
	float frequency;
	float phase;
	float index;
};

#endif