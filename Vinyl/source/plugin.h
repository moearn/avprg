#ifndef __plugin__
#define __plugin__
#include "pluginadapter.h"
#include "VinylProcessor.h"

namespace Steinberg {
namespace Vst {

// change these numbers!
// every plugin needs a unique UID
static const FUID PluginProcessorUID (0x89E8A45F, 0x92554F53, 0x96FAE413, 0x3C935A18);
static const FUID PluginControllerUID (0xD39D5B65, 0xD8AF42FA, 0x143F4AC8, 0x41EB44F0);

// define parameter tags here:
enum
{
	/** parameter ID */
	kVibratoFrequencyId = 0,
	kVibratoDepthId = 1,
	kHissDepthId = 2,
	kCrackleDepthId = 3,
	kCrackleAmountId = 4,
	kWearId = 5,
	kHumVolumeId = 6,
	kHumMidFreqId = 7,
	kHumHighFreqId = 8,
	kHumMidDepthId = 9,
	kHumHighDepthId = 10,
	kGainId = 11
};


class Plugin : public PluginAdapter
{
public:
	Plugin ();
	virtual ~Plugin (){}
	tresult PLUGIN_API process (ProcessData& data);
	void startProcessing(int numChannels, SampleRate sampleRate);	
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new Plugin (); }
private:
	int numChannels;
	SampleRate sampleRate;
private:
	VinylProcessor leftProcessor;
	VinylProcessor rightProcessor;
};




}} // namespaces

#endif //__plugin__
