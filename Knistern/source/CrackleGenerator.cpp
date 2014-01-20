#include "CrackleGenerator.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

CrackleGenerator::CrackleGenerator() 
	: amount(0), index(0) {}

void CrackleGenerator::initialize(float* samples, int length){
	this->crackleSamples = samples;
	this->crackleLength = length;
	this->crackleVolume = 1; // internal volume for ONE crack, not overall depth!!!
	srand (time(NULL));
}

void CrackleGenerator::setAmount(float amount) {
	this->amount = amount;
}

float CrackleGenerator::getValue() {

	// output
	float value = 0;

	// crackle currently not "playing"
	if (index == 0) {

		float chance = amount/2;													  // cap at 50% (its every 2nd sample!!!);
		float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); // random number between 0.0 and 1.0

		if (random <= chance) {
			// start playing crackle sound
			crackleVolume = 0.5 + random; // iwas zwischen 0.5 und 1.0
			value = crackleSamples[index];
			index++;
		}

	}

	// crackle is unfinished / "playing"
	else {
		if(index < crackleLength) {
			// sample zu ende abspielen
			value = crackleSamples[index];
			index++;
		}
		else {
			// has ended
			index = 0;
		}
	}

	return value * crackleVolume;
}