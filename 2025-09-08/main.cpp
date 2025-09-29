#include <iostream>

int main()
{
    int x;
    std::cin >> x;

    int base = 16;
    for (int i = 0; i < 32; ++i)
    {
        std::cout << x % base << ' ';
        x /= base;
    }
    std::cout << '\n';

    return 0;
}
