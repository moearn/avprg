#ifndef LFO_H
#define LFO_H

class Lfo
{
public:
        Lfo();
        void initialize(double sampleRate);
        void setFrequency(float frequency);
        void setPhase(float phase);
        float getValue();
private:
        double sampleRate;
        int index;
        float phase;
        float frequency;
};

#endif
