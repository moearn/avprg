#include "plugin.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
// member function of PluginController!
// define parameter definitions here...
void PluginController::setupParameters(){
	parameters.addParameter(new RangeParameter(STR16("Frequenz"), kFreqId, STR16("Hz"), 0.000, 1));
	parameters.addParameter(new RangeParameter(STR16("SweepDepth"), kSweepDepthId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Depth (Min Delay)"), kDepthId, STR16("ms"), 0, 10));
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
    if (hasInputParameterChanged(data, kFreqId)){
        float freq = getInputParameterChange(data, kFreqId);
		freq = freq == 0 ? 0.0001 : freq; // rescale
		leftProcessor.setLfoFrequency(freq);
		rightProcessor.setLfoFrequency(freq);
    }
	if (hasInputParameterChanged(data, kDepthId)){
        float depth = getInputParameterChange(data, kDepthId);
		depth = depth / 1000 * 10; // rescale to ms
		leftProcessor.setFlangerDepth(depth);
		rightProcessor.setFlangerDepth(depth);
    }
	if (hasInputParameterChanged(data, kSweepDepthId)){
        float sweepDepth = getInputParameterChange(data, kSweepDepthId);
		leftProcessor.setLfoDepth(sweepDepth);
		rightProcessor.setLfoDepth(sweepDepth);
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

