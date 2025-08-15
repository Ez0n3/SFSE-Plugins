#pragma once
#include "sfse_common/sfse_version.h" // SFSE
#include "sfse_common/Log.h"	// Needed for SFSE
#include "sfse_common/Errors.h"	// Needed for SFSE
#include "IVersionCheck.h" // Common plugin version check, found in \common\common_plugins\
// #include "../plugin_common/common.h" // EG: Common plugin functions for this sdk if needed

// ================================
// Plugin Information
// ================================

// Plugin info
#define PLUGIN_AUTHOR				"Ez0n3"					// Author of the plugin

#define PLUGIN_NAME_SHORT			"ez_sfse_plugin_example"	// Plugin name without spaces
#define PLUGIN_NAME_LONG			"Ez SFSE Plugin Example"	// Plugin name with spaces

// Plugin version, Major, Minor, Build. EG: (1.0.0) equals (Major.Minor.Build)
#define PLUGIN_VERSION_MAJOR		1
#define PLUGIN_VERSION_MINOR		0
#define PLUGIN_VERSION_BUILD		0

// ================================
// Nothing below this needs changing between plugins except maybe MINIMUM_RUNTIME_VERSION and/or SUPPORTED_RUNTIME_VERSION_STRICT
// ================================

// Plugin log file
#define PLUGIN_LOG_FILE				"\\My Games\\" GAME_SAVE_FOLDER_NAME("Starfield") "\\SFSE\\" PLUGIN_LOG_FILE_NAME(PLUGIN_NAME_SHORT) // plugin log file location

// Common definitions
#define SDK_VERSION_STRING			VERSION_TO_STRING(SFSE_VERSION_INTEGER, SFSE_VERSION_INTEGER_MINOR, SFSE_VERSION_INTEGER_BETA)
#define PLUGIN_VERSION_STRING		VERSION_TO_STRING(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_BUILD)

#define PLUGIN_VERSION_DLL			MAKE_EXE_VERSION(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_BUILD)
#define PLUGIN_VERSION_INFO			PLUGIN_NAME_SHORT " v%s (0x%08X) (SDK v%s)", PLUGIN_VERSION_STRING, PLUGIN_VERSION_DLL, SDK_VERSION_STRING

// ================================
// Plugin Version Information
// ================================

// The minimum runtime version allowed by the plugin. EG: I need function X, which was added in runtime Y, therefore Y is the minimum runtime version
#define MINIMUM_RUNTIME_VERSION				RUNTIME_VERSION_0_0_3	// The lowest version

// The runtime version the plugin was designed for
// #define SUPPORTED_RUNTIME_VERSION		CURRENT_RELEASE_RUNTIME
#define SUPPORTED_RUNTIME_VERSION			RUNTIME_VERSION // Set in /config/_Plugins.props, controls core and plugin versions - normally latest

// Strict runtime version. If strict=true, runtime and supported versions must match. If strict=false, runtime version must be above the minimum
#define SUPPORTED_RUNTIME_VERSION_STRICT	false

// The compatible runtime version - set automatically
#define COMPATIBLE(runtimeVersion)			(runtimeVersion == SUPPORTED_RUNTIME_VERSION)

// ================================

/*
// From sfse_version.h

#define RUNTIME_VERSION_0_0_3		MAKE_EXE_VERSION(0, 0, 3)		// 0x00000030	ms store early versions (no one has these)
#define RUNTIME_VERSION_1_0_17		MAKE_EXE_VERSION(1, 0, 17)		// 0x01000110	ms store early versions (no one has these)
#define RUNTIME_VERSION_1_2_20		MAKE_EXE_VERSION(1, 2, 20)		// 0x01020140	ms store early versions (no one has these)
#define RUNTIME_VERSION_1_6_35		MAKE_EXE_VERSION(1, 6, 35)		// 0x01060230	version reported by ms store before release (no one has these)
#define RUNTIME_VERSION_1_7_23		MAKE_EXE_VERSION(1, 7, 23)		// 0x01070170	early access/wide release patch
#define RUNTIME_VERSION_1_7_29		MAKE_EXE_VERSION(1, 7, 29)		// 0x010701D0
#define RUNTIME_VERSION_1_7_33		MAKE_EXE_VERSION(1, 7, 33)		// 0x01070210
#define RUNTIME_VERSION_1_7_36		MAKE_EXE_VERSION(1, 7, 36)		// 0x01070240
#define RUNTIME_VERSION_1_8_83		MAKE_EXE_VERSION(1, 8, 83)		// 0x01080530	beta
#define RUNTIME_VERSION_1_8_84		MAKE_EXE_VERSION(1, 8, 84)		// 0x01080540	beta
#define RUNTIME_VERSION_1_8_86		MAKE_EXE_VERSION(1, 8, 86)		// 0x01080560	beta released to main branch
#define RUNTIME_VERSION_1_8_87		MAKE_EXE_VERSION(1, 8, 87)		// 0x01080570	beta
#define RUNTIME_VERSION_1_8_88		MAKE_EXE_VERSION(1, 8, 88)		// 0x01080580	(very) small patch
#define RUNTIME_VERSION_1_9_51		MAKE_EXE_VERSION(1, 9, 51)		// 0x01090330
#define RUNTIME_VERSION_1_9_67		MAKE_EXE_VERSION(1, 9, 67)		// 0x01090430	beta released to main branch
#define RUNTIME_VERSION_1_9_71		MAKE_EXE_VERSION(1, 9, 71)		// 0x01090470	hotfix
#define RUNTIME_VERSION_1_10_30		MAKE_EXE_VERSION(1, 10, 30)		// 0x010A01E0	beta
#define RUNTIME_VERSION_1_10_31		MAKE_EXE_VERSION(1, 10, 31)		// 0x010A01F0	
#define RUNTIME_VERSION_1_10_32		MAKE_EXE_VERSION(1, 10, 32)		// 0x010A0200	hotfix
#define RUNTIME_VERSION_1_11_33		MAKE_EXE_VERSION(1, 11, 33)		// 0x010B0210	beta
#define RUNTIME_VERSION_1_11_36		MAKE_EXE_VERSION(1, 11, 36)		// 0x010B0240	
#define RUNTIME_VERSION_1_12_30		MAKE_EXE_VERSION(1, 12, 30)		// 0x010C01E0	editor released
#define RUNTIME_VERSION_1_12_32		MAKE_EXE_VERSION(1, 12, 32)		// 0x010C0200	hotfix
#define RUNTIME_VERSION_1_12_36		MAKE_EXE_VERSION(1, 12, 36)		// 0x010C0240
#define RUNTIME_VERSION_1_13_61		MAKE_EXE_VERSION(1, 13, 61)		// 0x010D03D0	car
#define RUNTIME_VERSION_1_14_70		MAKE_EXE_VERSION(1, 14, 70)		// 0x010E0460	xp1
#define RUNTIME_VERSION_1_14_74		MAKE_EXE_VERSION(1, 14, 74)		// 0x010E04A0	beta released to main branch
#define RUNTIME_VERSION_1_15_214	MAKE_EXE_VERSION(1, 15, 214)	// 0x010F0D60	beta
#define RUNTIME_VERSION_1_15_215	MAKE_EXE_VERSION(1, 15, 215)	// 0x010F0D70	beta
#define RUNTIME_VERSION_1_15_216	MAKE_EXE_VERSION(1, 15, 216)	// 0x010F0D80	inlining options changed
*/

