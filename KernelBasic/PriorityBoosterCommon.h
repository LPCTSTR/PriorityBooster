#pragma once


typedef unsigned long ULONG;


#define PRIORITY_BOOSTER_DEVICE 0x8000

#define IOCTL_PRIORITY_BOOSTER_SET_PRIORITY CTL_CODE(PRIORITY_BOOSTER_DEVICE, \
0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

/*
(Note that we cannot normally use DWORD - a common type defined in user mode headers
- because it's not defined in kernel mode headers. 
ULONG, on the other hand, is defined in both).
*/
struct ThreadData {
	ULONG ThreadId;
	int Priority;
};

