// User Defines
#include "config.h"
// SFSE
#include "sfse/PluginAPI.h"
#include "sfse/GameConsole.h" // Print to console
// Windows
#include <shlobj.h>	// CSIDL_MYCODUMENTS

//#include "sfse/PapyrusNativeFunctions.h" // FIXME - Error
//#include "sfse_common/SafeWrite.h" // FIXME - Error

// NOTE: This plugin is currently UNTESTED, but it should work based on similarities with all other SDks
// NOTE: This is a WIP, currently I have not found a way to create a new function that interfaces with game scripts
// NOTE: Although there is not a way to interface with game scripts, the messaging listener and other interfaces should work

// ================================
// Handles
// ================================

// Handle for the plugin
PluginHandle g_pluginHandle = kPluginHandle_Invalid;

/*
// FIXME - this is not working yet
// Handle for the papyrus interface
static SFSEPapyrusInterface* g_papyrus = NULL; // SFSE does use Papyrus, FIXME - integrate!
*/

// Handle for other things...

/* // Uncomment to use messaging
// Handle for the messaging interface
static SFSEMessagingInterface* g_messaging = NULL;
*/

// ================================
// User Code
// ================================

// Example namespace and test bool function to print Hello World!
namespace Plugin_Example_Functions
{
	bool Test() //StaticFunctionTag *base // FIXME - try with?
	{
		_MESSAGE("Hello World!"); // print to the plugin log
		Console_Print("Hello Console!"); // print to the in-game console
		return true;
	}
}

// ================================
// Plugin Listener
// ================================

/* // Uncomment to use messaging
// Listener for the plugin
static void PluginListener(SFSEMessagingInterface::Message* msg) noexcept
{
	switch (msg->type) {
		// case SFSEMessagingInterface::kMessage_PostLoad:
		case SFSEMessagingInterface::kMessage_PostPostLoad:
		{
			_MESSAGE("PluginListener: kMessage_PostPostLoad");
			break;
		}
		// case SFSEMessagingInterface::kMessage_PostDataLoad:
		case SFSEMessagingInterface::kMessage_PostPostDataLoad:
		{
			_MESSAGE("PluginListener: kMessage_PostPostDataLoad");
			break;
		}
		// case SFSEMessagingInterface::kMessage_PreSaveGame:
		// case SFSEMessagingInterface::kMessage_PostSaveGame:
		// case SFSEMessagingInterface::kMessage_PreLoadGame:
		// case SFSEMessagingInterface::kMessage_PostLoadGame:
	}
}
*/

// ================================
// Plugin Compatibility Check
// ================================

// Check that the runtime and plugin versions are compatible
const bool IsCompatible(const SFSEInterface* sfse)
{
	// check for compatible version. if strict=true, runtime and supported versions must match. if strict=false, runtime version must be above the minimum
	if (!IVersionCheck::IsCompatibleVersion(sfse->runtimeVersion, MINIMUM_RUNTIME_VERSION, SUPPORTED_RUNTIME_VERSION, SUPPORTED_RUNTIME_VERSION_STRICT)) { // not strict
		_MESSAGE("ERROR::IsCompatible: Plugin is not compatible with runtime version, disabling");
		_FATALERROR("ERROR::IsCompatible: Plugin is not compatible with runtime version, disabling");
		
		// not compatible
		return false;
	}
	
	// compatible
	return true;
}

// ================================
// Plugin Export, Query and Load - Start Extern-C
// ================================

extern "C" { // Start: extern "C"

// ================================
// Plugin Version Data - Not Used In All SE SDK's
// ================================

// Export the plugin version data to f4se, without this the plugin will fail to load. See: PluginAPI.h
__declspec(dllexport) SFSEPluginVersionData SFSEPlugin_Version =
{
	SFSEPluginVersionData::kVersion, // sfse expects plugin version info to follow this structure
	
	PLUGIN_VERSION_DLL,		// set in config.h
	PLUGIN_NAME_LONG, 		// set in config.h
	PLUGIN_AUTHOR, 			// set in config.h


    // SFSEPluginVersionData::kAddressIndependence_Signatures,
	0,	// not address independent
	// SFSEPluginVersionData::kStructureIndependence_NoStructs,
	0,	// not structure independent
	
	// { RUNTIME_VERSION_1_7_23, 0 },	// compatible with 1.7.23 and that's it	
	{ SUPPORTED_RUNTIME_VERSION, 0 },	// set in config.h
	
	0,	// works with any version of the script extender. you probably do not need to put anything here
	
	0, 0,	// set these reserved fields to 0
};

// ================================
// Plugin Query - Not Used In All SE SDK's
// ================================

/*
// SFSE does not use this
bool SFSEPlugin_Query(const SFSEInterface* sfse, PluginInfo* info)
{
}
*/

// ================================
// Plugin Preload - Not Used In All SE SDK's
// ================================

/*
// If your plugin needs to make modifications before global initializers, add and export this:
// Note: Game and SFSE functionality may be limited during preload
bool SFSEPlugin_Preload(const SFSEInterface* sfse)
{
	_MESSAGE("Plugin_Preload: Preloading");
	
	// User Code
	
	_MESSAGE("Plugin_Preload: Preloaded");
	
	return true;
}
*/

// ================================
// Plugin Load - Used In All SE SDK's
// ================================

// SFSE Plugin Load - Called when the plugin loads everytime
bool SFSEPlugin_Load(const SFSEInterface* sfse)
{
	// This is not needed for SFSE, it handles this internally instead of using common_vc#
	// open the plugin log file
	// gLog.OpenRelative(CSIDL_MYDOCUMENTS, PLUGIN_LOG_FILE);

	_MESSAGE(PLUGIN_VERSION_INFO); // write the plugin version to the log
	_MESSAGE("Plugin_Load: Loading");
	
	// check for compatible versions
	if (!IsCompatible(sfse)) {
		_MESSAGE("ERROR::Plugin_Load: Incompatible | Disabling Plugin");
		_FATALERROR("ERROR::Plugin_Load: Incompatible | Disabling Plugin");
		// incompatible
		return false;
	}
	
	// FIXME - this should be in PreLoad instead? Maybe only if PreLoad is needed?
	// store plugin handle for later
	g_pluginHandle = sfse->GetPluginHandle();
	
	/*
	// FIXME - this does not work yet
	// register the new functions
	if (g_papyrus->Register(RegisterFuncs)) {
		_MESSAGE("Plugin_Load: Functions Registered");
	}
	*/
	
	/* // Uncomment to use messaging
	// register the listener
	g_messaging = (SFSEMessagingInterface*)sfse->QueryInterface(kInterface_Messaging);
	if (g_messaging) {
		if (g_messaging->RegisterListener(g_pluginHandle, "SFSE", PluginListener)) {
			_MESSAGE("Plugin_Load: Listener Registered");
		}
	}
	*/
	
	_MESSAGE("Plugin_Load: Loaded Successfully"); // log the successful load

	// initialized
	return true;
}

}; // Stop: extern "C"

// ================================
