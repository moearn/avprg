#ifndef FLANGER_PROCESSOR_H
#define FLANGER_PROCESSOR_H

#include "Lfo.h"
#include "Ringbuffer.h"


const float DELAY_MAX_SEC = 10.0 / 1000.0;        // max 10 ms Delay
const float FREQUENCY_DEFAULT_HZ = 0.01;
const float FREQUENCY_MAX_HZ = 0.1;
const float DEPTH_DEFAULT_PERCENT = 50;


class FlangerProcessor{
public:
        FlangerProcessor();
        void initialize(float sampleRate);
        float processOneSample(float);
        void process(float* input, float*output, int numberOfSamples);
        void setFrequency(float frequency);
        void setDepth(float depth);
		void setDelay(float delay);
		void setSweepDepth(float sweepDepth);
private:
        float sampleRate;
        Lfo lfo;
        Ringbuffer buffer;
        float depth;
		float sweepDepth;
		float delay;
};
#endif