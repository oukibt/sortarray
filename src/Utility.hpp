#pragma once
#include "SDK/amx/amx.h"
#include <xstring>
#include <windows.h>

namespace sortarray
{
	int PawnArrayConvert(AMX *amx, int *array, cell input, cell count); //in
	int PluginArrayConvert(AMX *amx, int *array, cell input, cell count); //out
	int sort(int *array, const int size);
	int asort(int *array, const int size);
};