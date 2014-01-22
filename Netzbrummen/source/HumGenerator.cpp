#include "HumGenerator.h"

HumGenerator::HumGenerator() : baseAmount(0.40), midAmount(0.20), highAmount(0.20)
{}

void HumGenerator::initialize(float sampleRate) {
	baseFreqLfos[0].initialize(sampleRate, 50); // base Freqency cannot be changed. 50Hz is a standard almost all over the world (except US)
	baseFreqLfos[1].initialize(sampleRate, 150); 
	baseFreqLfos[2].initialize(sampleRate, 250);

	midFreqLfos[0].initialize(sampleRate, 500);
	midFreqLfos[1].initialize(sampleRate, 550);
	midFreqLfos[2].initialize(sampleRate, 600);

	highFreqLfos[0].initialize(sampleRate, 5000);
	highFreqLfos[1].initialize(sampleRate, 5050);
	highFreqLfos[2].initialize(sampleRate, 5100);
	highFreqLfos[3].initialize(sampleRate, 6100);
	highFreqLfos[4].initialize(sampleRate, 6200);
	highFreqLfos[5].initialize(sampleRate, 6300);
}


void HumGenerator::setBaseAmount(float amount) {
	this->baseAmount = amount;
}

void HumGenerator::setHighAmount(float amount) {
	this->highAmount = amount;
}

void HumGenerator::setHighFrequency(float freq) {
	highFreqLfos[0].setFrequency(freq-1000);
	highFreqLfos[1].setFrequency(freq-950);
	highFreqLfos[2].setFrequency(freq-900);

	highFreqLfos[3].setFrequency(freq-100);
	highFreqLfos[4].setFrequency(freq);
	highFreqLfos[5].setFrequency(freq+100);

}

void HumGenerator::setHighClarity(float clarity) {
	// to be implemented (only nice to have)
}

void HumGenerator::setMidAmount(float amount) {
	this->midAmount = amount;
}

void HumGenerator::setMidFrequency(float freq) {
	midFreqLfos[0].setFrequency(freq-50);
	midFreqLfos[1].setFrequency(freq);
	midFreqLfos[2].setFrequency(freq+50);

}

void HumGenerator::setMidClarity(float clarity) {
	// to be implemented (only nice to have)
}


float HumGenerator::getValue() {
	return  baseFreqLfos[0].getValue() * 0.80 + 
			baseFreqLfos[1].getValue() * 0.10 + 
			baseFreqLfos[2].getValue() * 0.10;
}


float HumGenerator::getBaseFreqValue() {
	return	midFreqLfos[0].getValue() * 0.30 + 
			midFreqLfos[0].getValue() * 0.40 + 
			midFreqLfos[0].getValue() * 0.30;
}


float HumGenerator::getMidFreqValue() {
	return	highFreqLfos[0].getValue() * 0.15 +
			highFreqLfos[1].getValue() * 0.20 +
			highFreqLfos[2].getValue() * 0.15 +
			highFreqLfos[3].getValue() * 0.15 +
			highFreqLfos[4].getValue() * 0.20 +
			highFreqLfos[5].getValue() * 0.15;
}

float HumGenerator::getHighFreqValue() {
	float hum = getBaseFreqValue() * baseAmount +
				getMidFreqValue()  * midAmount +
				getHighFreqValue() * highAmount;

	return hum;
}