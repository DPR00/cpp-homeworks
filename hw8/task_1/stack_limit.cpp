#include <iostream>

int main()
{
    const int N = 1024 * 8100;

    std::byte data[N];

    for (size_t i = 0; i < N; i++)
    {
        data[i] = std::byte(1);
        std::cerr << (i + 1) / 1024 << "[KiB] Allocated in the stack" << std::endl;
    }

    return 0;
}