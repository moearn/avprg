#ifndef LFO_H_
#define LFO_H_

class Lfo {
public:
	Lfo(void);
	~Lfo(void);
	void initialize(float sampleRate);
	void setFrequency(float frequency);
	float getValue();
private:
	float sampleRate;
	float frequency;
	float index;
};

#endif