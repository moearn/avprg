#include "plugin.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
// member function of PluginController!
// define parameter definitions here...
void PluginController::setupParameters(){

	parameters.addParameter(new RangeParameter(STR16("Gain"), kGainId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Staub"), kCrackleDepthId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Staub: Menge"), kCrackleAmountId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Leiern"), kVibratoDepthId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Leiern: Frequenz"), kVibratoFrequencyId, STR16("Hz"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Rauschen"), kHissDepthId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Verschleiss"), kWearId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Netzbrummen"), kHumVolumeId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Netzbrummen: Mid Frequency"), kHumMidFreqId, STR16("Hz"), 1500, 2900));
	parameters.addParameter(new RangeParameter(STR16("Netzbrummen: Mid Depth"), kHumMidDepthId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Netzbrummen: High Frequency"), kHumHighFreqId, STR16("Hz"), 3000, 8000));
	parameters.addParameter(new RangeParameter(STR16("Netzbrummen: High Depth"), kHumHighDepthId, STR16("%"), 0, 100));

}


//-----------------------------------------------------------------------------
Plugin::Plugin ()
: numChannels(0)
, sampleRate(0)
{
	setControllerClass (PluginControllerUID);
}
//-----------------------------------------------------------------------------
void Plugin::startProcessing(int numChannels, SampleRate sampleRate){
	this->numChannels = numChannels;
	this->sampleRate = sampleRate;
	leftProcessor.initialize(sampleRate);
	rightProcessor.initialize(sampleRate);
}
tresult PLUGIN_API Plugin::process (ProcessData& data)
{
	//Vibrato
    if (hasInputParameterChanged(data, kVibratoFrequencyId)){
        float frequency = getInputParameterChange(data, kVibratoFrequencyId);
		leftProcessor.setVibratoFrequency(frequency);
		rightProcessor.setVibratoFrequency(frequency);
    }
	if (hasInputParameterChanged(data, kVibratoDepthId)){
        float depth = getInputParameterChange(data, kVibratoDepthId);
		leftProcessor.setVibratoDepth(depth);
		rightProcessor.setVibratoDepth(depth);
    }

	//Rauschen
	if (hasInputParameterChanged(data, kHissDepthId)){
        float depth = getInputParameterChange(data, kHissDepthId);
		leftProcessor.setHissDepth(depth);
		rightProcessor.setHissDepth(depth);
    }

	//Crackle
	if (hasInputParameterChanged(data, kCrackleAmountId)){
        float amount = getInputParameterChange(data, kCrackleAmountId);
		leftProcessor.setCrackleAmount(amount);
		rightProcessor.setCrackleAmount(amount);
    }
	if (hasInputParameterChanged(data, kCrackleDepthId)){
        float depth = getInputParameterChange(data, kCrackleDepthId);
		depth = depth/2;
		leftProcessor.setCrackleDepth(depth);
		rightProcessor.setCrackleDepth(depth);
    }

	//Mainshum
	if (hasInputParameterChanged(data, kHumVolumeId)){
        float vol = getInputParameterChange(data, kHumVolumeId);
		leftProcessor.setHumVolume(vol);
		rightProcessor.setHumVolume(vol);
    }
	if (hasInputParameterChanged(data, kHumMidFreqId)){
        float midFreq = getInputParameterChange(data, kHumMidFreqId);
		midFreq = midFreq * 1400 + 1500; // scale to 500 - 1500 Hz
		leftProcessor.setHumMidFrequency(midFreq);
		rightProcessor.setHumMidFrequency(midFreq);
    }
	if (hasInputParameterChanged(data, kHumHighFreqId)){
        float highFreq = getInputParameterChange(data, kHumHighFreqId);
		highFreq = highFreq * 5000 + 3000;
		leftProcessor.setHumHighFrequency(highFreq);
		rightProcessor.setHumHighFrequency(highFreq);
    }
	if (hasInputParameterChanged(data, kHumMidDepthId)){
        float midDepth = getInputParameterChange(data, kHumMidDepthId);
		leftProcessor.setHumMidDepth(midDepth);
		rightProcessor.setHumMidDepth(midDepth);
    }
	if (hasInputParameterChanged(data, kHumHighDepthId)){
        float highDepth = getInputParameterChange(data, kHumHighDepthId);
		leftProcessor.setHumHighDepth(highDepth);
		rightProcessor.setHumHighDepth(highDepth);
    }

	//Wear
	if (hasInputParameterChanged(data, kWearId)){
        float wear = getInputParameterChange(data, kWearId);
		leftProcessor.setWear(wear);
		rightProcessor.setWear(wear);
    }

	//Gain
	if (hasInputParameterChanged(data, kGainId)){
        float gain = getInputParameterChange(data, kGainId);
		leftProcessor.setGain(gain);
		rightProcessor.setGain(gain);
    }

 	if (numChannels > 0){
		float* leftInputChannel = data.inputs[0].channelBuffers32[0];
		float* leftOutputChannel = data.outputs[0].channelBuffers32[0];
		leftProcessor.process(leftInputChannel, leftOutputChannel, data.numSamples);
	}
	if (numChannels > 1){
		float* rightInputChannel = data.inputs[0].channelBuffers32[1];
		float* rightOutputChannel = data.outputs[0].channelBuffers32[1];
		rightProcessor.process(rightInputChannel, rightOutputChannel, data.numSamples);
	}
	return kResultTrue;
}


}} // namespaces

