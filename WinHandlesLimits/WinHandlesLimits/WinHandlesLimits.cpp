#include <iostream>
#include <windows.h>

int main()
{
    auto const h = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());

    for (auto handleCount = 0; ; handleCount++)
    {
        HANDLE dup;

        if (!DuplicateHandle(
            GetCurrentProcess(),
            h,
            GetCurrentProcess(),
            &dup,
            0,
            FALSE,
            DUPLICATE_SAME_ACCESS))
        {
            std::cout << "Total handles: " << handleCount << std::endl;
            return -1;
        }
    }
}
