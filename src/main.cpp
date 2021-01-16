#include <cstddef>

#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"
#include "pluginconfig.h"
#include "SortArray\Utility.cpp"
#include <xstring>
#include <cstdlib>
#include <cstdio>
#include <windows.h>

#define ASSERT_PARAMS(a) if(((int)params[0] / (int)sizeof cell) < a) return 0;

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_BUILD 1

using namespace std;
using namespace sortarray;

extern void *pAMXFunctions;
void *(*logprintf)(const char *fmt, ...);

cell AMX_NATIVE_CALL sort(AMX *amx, cell *params)
{
	ASSERT_PARAMS(2);

	int *array = new int[params[2]];
	
	PawnArrayConvert(amx, array, params[1], params[2]);
	
	sort(array, params[2]);

	PluginArrayConvert(amx, array, params[1], params[2]);

	delete []array;
	return 1;
}

cell AMX_NATIVE_CALL asort(AMX *amx, cell *params)
{
	ASSERT_PARAMS(2);

	int *array = new int[params[2]];
	
	PawnArrayConvert(amx, array, params[1], params[2]);
	
	asort(array, params[2]);

	PluginArrayConvert(amx, array, params[1], params[2]);

	delete []array;
	return 1;
}

static AMX_NATIVE_INFO plugin_natives[] =
{
	{ "sort", sort },
	{ "asort", asort }
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return PLUGIN_SUPPORTS_FLAGS;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (void *(*)(const char *fmt, ...))ppData[PLUGIN_DATA_LOGPRINTF];
	if (NULL == pAMXFunctions || NULL == logprintf) return false;
	logprintf("  %s plugin v%d.%d.%d by oukibt was loaded", PLUGIN_NAME, VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD);
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf("  %s plugin was unloaded", PLUGIN_NAME);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	amx_Register(amx, plugin_natives, (int)arraysize(plugin_natives));
	return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}