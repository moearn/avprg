#include "Lfo.h"
#include <math.h> /*sin*/

#define PI 3.14159265

Lfo::Lfo(void) 
	: index(0), sampleRate(0), frequency(0)
{
}

Lfo::~Lfo(void) {}

void Lfo::initialize(float sampleRate) {
	this->sampleRate = sampleRate;
}

void Lfo::setFrequency(float frequency) {
	this->frequency = frequency;
}

float Lfo::getValue() {
	float value = sin (2 * PI * index * frequency / sampleRate);
	value = (value + 1) * 0.5; // transform from (-1/1) to (0/1)
	index++;
	return value;
}