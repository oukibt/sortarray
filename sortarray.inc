// sortarray plugin by oukibt 16 Jan 2021

native sort(array[], count = sizeof array);
native asort(array[], count = sizeof array);

#undef DONT_DEFINE_THIS_AAAA
#if defined DONT_DEFINE_THIS_AAAA

example
{
	new sort_this_ascending[] = { 12, 254, 1, 432, 11, 467, 1 };
	sort(sort_this_ascending);
	for(new i; i < sizeof sort_this_ascending; i++) printf("%d ", sort_this_ascending[i]); // 1 1 11 12 254 432 467

	new sort_this_descending[] = { 12, 254, 1, 432, 11, 467, 1 };
	asort(sort_this_descending);
	for(new i; i < sizeof sort_this_descending; i++) printf("%d ", sort_this_descending[i]); // 467 432 254 12 11 1 1
}

#endif