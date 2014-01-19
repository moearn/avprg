#include <math.h>
#include "Lfo.h"

const float pi = 3.1415926f;

Lfo::Lfo()
: sampleRate(0)
, index(0)
, frequency(0)
, phase(0)
{}
void Lfo::initialize(double sampleRate){
        this->sampleRate = sampleRate;
        this->index = 0;
}

void Lfo::setFrequency(float frequency){
        this->frequency = frequency;
}
void Lfo::setPhase(float phase){
        this->phase = phase;
}
float Lfo::getValue(){
        float value = sin(2 * pi * index * frequency / sampleRate + phase);
        index++;
        return 0.5 * (value + 1);
}
