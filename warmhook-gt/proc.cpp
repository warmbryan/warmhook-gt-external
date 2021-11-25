#include <iostream>
#include "proc.h"

uintptr_t GetProcessId(const wchar_t* processName)
{
	uintptr_t processId = 0;
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		do
		{
			if (!wcscmp(pe32.szExeFile, processName))
			{
				processId = pe32.th32ProcessID;
				break;
			}

		} while (Process32Next(hProcessSnap, &pe32));
	}
	CloseHandle(hProcessSnap);
	return processId;
}

uintptr_t GetModuleBaseAddress(uintptr_t processId, const wchar_t* moduleName)
{
	uintptr_t moduleBaseAddress = 0;
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);

	if (hProcessSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 moduleEntry;
		moduleEntry.dwSize = sizeof(moduleEntry);

		do
		{
			if (!wcscmp(moduleEntry.szModule, moduleName))
			{
				moduleBaseAddress = (uintptr_t)moduleEntry.modBaseAddr;
				break;
			}
		} while (Module32Next(hProcessSnap, &moduleEntry));
	}

	CloseHandle(hProcessSnap);
	return moduleBaseAddress;
}