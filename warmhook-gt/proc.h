#include <Windows.h>
#include <TlHelp32.h>

uintptr_t GetProcessId(const wchar_t* processName);
uintptr_t GetModuleBaseAddress(uintptr_t processId, const wchar_t* moduleName);