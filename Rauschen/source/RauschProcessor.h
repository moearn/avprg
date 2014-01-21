#ifndef RAUSCH_PROCESSOR_H
#define RAUSCH_PROCESSOR_H

#include "Lfo.h"
#include "Ringbuffer.h"

const float FREQUENCY_DEFAULT_HZ = 0.01;
const float FREQUENCY_MAX_HZ = 0.1;
const float DEPTH_DEFAULT_PERCENT = 50;


class RauschProcessor{
public:
        RauschProcessor();
        void initialize(float sampleRate);
        float processOneSample(float input);
        void process(float* input, float*output, int numberOfSamples);
        void setDepth(float depth);
		void setSweep(float sweep);
private:
        float sampleRate;
        Ringbuffer buffer;
        float depth;
		float sweep;
};
#endif