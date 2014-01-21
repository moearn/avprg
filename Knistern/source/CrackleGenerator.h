#ifndef CrackleGenerator_H_
#define CrackleGenerator_H_

class CrackleGenerator {
public:
	CrackleGenerator();
	void initialize(float* samples, int length, int gapLength);
	void setAmount(float amount);
	float getValue();
private:
	int index;
	int gapLength;
	float* crackleSamples;
	int crackleLength;
	float crackleVolume;
	float amount;
};

#endif