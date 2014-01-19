#ifndef __plugin__
#define __plugin__
#include "pluginadapter.h"
#include "RauschProcessor.h"

namespace Steinberg {
namespace Vst {

// change these numbers!
// every plugin needs a unique UID
static const FUID PluginProcessorUID (0x89E8CE5F, 0x92554F53, 0x16FAF513, 0x3C935A18);
static const FUID PluginControllerUID (0xD39F5B95, 0xD8AF42FA, 0x142F4AC8, 0x41EB04F0);

// define parameter tags here:
enum
{
	/** parameter ID */
	kDepthId = 0
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
	RauschProcessor leftProcessor;
	RauschProcessor rightProcessor;
	ParamValue depth;
};




}} // namespaces

#endif //__plugin__
