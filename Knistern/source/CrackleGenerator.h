#ifndef CrackleGenerator_H_
#define CrackleGenerator_H_

class CrackleGenerator {
public:
	CrackleGenerator(void);
	~CrackleGenerator(void);
	void initialize(float* samples, int length);
	void setAmount(float amount);
	float getValue();
private:
	int index;
	float* crackleSamples;
	int crackleLength;
	float crackleVolume;
	float amount;
};

#endif