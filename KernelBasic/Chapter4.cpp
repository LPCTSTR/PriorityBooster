/*
#include<ntddk.h>

UNICODE_STRING g_RegistryPath;


// define a tag (because of little endianess, viewed in PoolMon as 'lpct')
#define DRIVER_TAG 'tcpl'

NTSTATUS AllocateMemory(_In_ PUNICODE_STRING RegistryPath) {
	g_RegistryPath.Buffer = (WCHAR*)ExAllocatePoolWithTag
	(
		PagedPool,
		RegistryPath->Length,
		DRIVER_TAG
	);

	if (g_RegistryPath.Buffer == nullptr) {
		DbgPrint("Failed to allocate the memory\n");
		return STATUS_INSUFFICIENT_RESOURCES;
	}

	g_RegistryPath.MaximumLength = RegistryPath->Length;
	RtlCopyUnicodeString(&g_RegistryPath, RegistryPath);

	DbgPrint("Copied registry path: %wZ\n", &g_RegistryPath);
	return STATUS_SUCCESS;
}




void MyDriverUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);
	ExFreePool(g_RegistryPath.Buffer);	//Very significant process to avoid leak.
	DbgPrint((" Module Unload Now!\n"));
}


extern "C"
NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
	//UNREFERENCED_PARAMETER(DriverObject);
	DriverObject->DriverUnload = MyDriverUnload;
	auto status = AllocateMemory(RegistryPath);

	return status;
}

*/

