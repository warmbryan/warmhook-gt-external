#include "proc.h"

int main()
{
    uintptr_t procId = GetProcessId(L"Growtopia.exe");
    uintptr_t procBaseAddr = GetModuleBaseAddress(procId, L"Growtopia.exe");

    /*207D13BC098 = 20FE0097330 + 8 = 20FE0097338

    207C7F11A00 = 207D13BBF00 + 198 = 207D13BC098

    Growtopia.exe + AB6B90 = 207C7F10F50 + AB0 = 207C7F11A00*/
    return 0;
}