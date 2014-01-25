#ifndef RAUSCH_PROCESSOR_H
#define RAUSCH_PROCESSOR_H

#include "Rauschen.h"

const float HISS_DEPTH_DEFAULT_PERCENT = 50;


class RauschProcessor{
public:
        RauschProcessor();
        void initialize(float sampleRate);
        float processOneSample(float input);
        void process(float* input, float*output, int numberOfSamples);
        void setDepth(float depth);
private:
        float sampleRate;
        float depth;
		Rauschen rauschen;
};
#endif