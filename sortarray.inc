// sortarray plugin by oukibt 16 Jan 2021

native sort(array[], count = sizeof array);
native asort(array[], count = sizeof array);

#undef DONT_DEFINE_THIS_AAAA
#if defined DONT_DEFINE_THIS_AAAA

example
{
	new sort_this_ascending[] = { -1, -2, 0, -3413, 210, 1, 431, 12 };
	sort(sort_this_ascending);
	for(new i; i < sizeof sort_this_ascending; i++) printf("%d ", sort_this_ascending[i]); // -3413 -2 -1 0 1 12 210 431

	new sort_this_descending[] = { -1, -2, 0, -3413, 210, 1, 431, 12 };
	asort(sort_this_descending);
	for(new i; i < sizeof sort_this_descending; i++) printf("%d ", sort_this_descending[i]); // 431 210 12 1 0 -1 -2 -3413
}

#endif