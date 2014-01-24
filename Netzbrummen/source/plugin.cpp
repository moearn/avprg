#include "plugin.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
// member function of PluginController!
// define parameter definitions here...
void PluginController::setupParameters(){
	parameters.addParameter(new RangeParameter(STR16("Lautstärke"), kVolumeId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Mid Frequency"), kMidFreqId, STR16("Hz"), 1500, 2900));
	parameters.addParameter(new RangeParameter(STR16("Mid Depth"), kMidDepthId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("High Frequency"), kHighFreqId, STR16("Hz"), 3000, 8000));
	parameters.addParameter(new RangeParameter(STR16("High Depth"), kHighDepthId, STR16("%"), 0, 100));
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
	if (hasInputParameterChanged(data, kVolumeId)){
        float vol = getInputParameterChange(data, kVolumeId);
		leftProcessor.setVolume(vol);
		rightProcessor.setVolume(vol);
    }
	if (hasInputParameterChanged(data, kMidFreqId)){
        float midFreq = getInputParameterChange(data, kMidFreqId);
		midFreq = midFreq * 1400 + 1500; // scale to 500 - 1500 Hz
		leftProcessor.setMidFrequency(midFreq);
		rightProcessor.setMidFrequency(midFreq);
    }
	if (hasInputParameterChanged(data, kHighFreqId)){
        float highFreq = getInputParameterChange(data, kHighFreqId);
		highFreq = highFreq * 5000 + 3000;
		leftProcessor.setHighFrequency(highFreq);
		rightProcessor.setHighFrequency(highFreq);
    }
	if (hasInputParameterChanged(data, kMidDepthId)){
        float midDepth = getInputParameterChange(data, kMidDepthId);
		leftProcessor.setMidDepth(midDepth);
		rightProcessor.setMidDepth(midDepth);
    }
	if (hasInputParameterChanged(data, kHighDepthId)){
        float highDepth = getInputParameterChange(data, kHighDepthId);
		leftProcessor.setHighDepth(highDepth);
		rightProcessor.setHighDepth(highDepth);
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

