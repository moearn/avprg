#ifndef __plugin__
#define __plugin__
#include "pluginadapter.h"
#include "FlangerProcessor.h"

namespace Steinberg {
namespace Vst {

// change these numbers!
// every plugin needs a unique UID
static const FUID PluginProcessorUID (0x89E8CE5F, 0x92554F53, 0x96FAF513, 0x3C935A18);
static const FUID PluginControllerUID (0xD39D5B95, 0xD8AF42FA, 0x142F4AC8, 0x41EB04F0);

// define parameter tags here:
enum
{
	/** parameter ID */
	kDelayId = 0,
	kDepthId = 1,
	kSweepDepthId = 2
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
	FlangerProcessor leftProcessor;
	FlangerProcessor rightProcessor;
	ParamValue depth;
	ParamValue delay;
	ParamValue sweepDeth;
};




}} // namespaces

#endif //__plugin__
