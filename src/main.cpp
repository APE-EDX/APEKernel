#include <Windows.h>
#include <inttypes.h>

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    uint64_t address = (uint64_t)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");

    DWORD dwWritten;
    HANDLE hPipe = CreateFile(TEXT("\\\\.\\pipe\\APEKernelPipe"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hPipe != INVALID_HANDLE_VALUE)
    {
        WriteFile(hPipe, (void*)&address, sizeof(uint64_t),  &dwWritten, NULL);
        CloseHandle(hPipe);
    }

    return 1;
}
