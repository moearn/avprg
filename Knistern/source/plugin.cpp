#include "plugin.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
// member function of PluginController!
// define parameter definitions here...
void PluginController::setupParameters(){
	parameters.addParameter(new RangeParameter(STR16("Crackle Amount"), kCrackleAmountId, STR16("%"), 0, 100));
	parameters.addParameter(new RangeParameter(STR16("Crackle Depth"), kCrackleDepthId, STR16("%"), 0, 100));
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
    if (hasInputParameterChanged(data, kCrackleAmountId)){
        float amount = getInputParameterChange(data, kCrackleAmountId);
		leftProcessor.setCrackleAmount(amount);
		rightProcessor.setCrackleAmount(amount);
    }
	if (hasInputParameterChanged(data, kCrackleDepthId)){
        float depth = getInputParameterChange(data, kCrackleDepthId);
		leftProcessor.setCrackleDepth(depth);
		rightProcessor.setCrackleDepth(depth);
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

