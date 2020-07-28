// PriorityBoosterClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <stdio.h>
#include "PriorityBoosterCommon.h"
#include <iostream>


int Error(const char* message) {
	printf("%s (error=%d)\n", message, GetLastError());
	return 1;
}

int main(int argc, const char* argv[]) {

	if (argc < 3) {
		printf("Usage: Booster <threadid> <priority>\n");
		return 0;
	}
	/*
	Notice the symbolic link "\\??\\PriorityBooster" points to \Device\PriorityBooster, 
	which is the internal name only accessible to kernel callers.
	And we should use "\\\\.\\PriorityBooster" as for "\\??\\PriorityBooster"
	*/
	HANDLE hDevice = CreateFile(L"\\\\.\\PriorityBooster", GENERIC_WRITE,
		FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
	if (hDevice == INVALID_HANDLE_VALUE)
		return Error("Failed to open device");

	ThreadData data;
	data.ThreadId = atoi(argv[1]);
	data.Priority = atoi(argv[2]);

	DWORD returned;
	BOOL success = DeviceIoControl(
		hDevice,
		IOCTL_PRIORITY_BOOSTER_SET_PRIORITY, // control code
		&data, sizeof(data), // input buffer and length
		nullptr, 0, // output buffer and length
		&returned, nullptr);
	if (success)
		printf("Priority change succeeded!\n");
	else
		Error("Priority change failed!");

	CloseHandle(hDevice);

}