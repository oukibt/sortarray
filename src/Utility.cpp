#pragma once
#include "SortArray\Utility.h"

using namespace std;

namespace sortarray
{
	int PawnArrayConvert(AMX *amx, int *array, cell input, cell count)
	{
		cell *addr;
		amx_GetAddr(amx, input, &addr);
		for(int i = 0; i < count; i++) array[i] = addr[i];
		return 1;
	}

	int PluginArrayConvert(AMX *amx, int *array, cell input, cell count)
	{
		cell *addr;
		amx_GetAddr(amx, input, &addr);
		for(int i = 0; i < count; i++) addr[i] = array[i];
		return 1;
	}

	int sort(int *array, const int size)
	{
		int i = 0, num = MAXINT32, b = 0;
		for(; i < size; i++)
		{
			for(b = i; b < size; b++)
			{
				if(array[b] > num) continue;
				num = array[b];
				swap(array[i], array[b]);
			}
			num = MAXINT32;
		}
		return 1;
	}

	int asort(int *array, const int size)
	{
		int i = 0, num = MININT32, b = 0;
		for(; i < size; i++)
		{
			for(b = i; b < size; b++)
			{
				if(num > array[b]) continue;
				num = array[b];
				swap(array[i], array[b]);
			}
			num = MININT32;
		}
		return 1;
	}
}