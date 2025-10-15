#include <iostream>

void get_bits(int b[32], int x, int base = 2)
{
    for (int i = 0; i < 32; ++i)
    {
        b[i] = x % base;
        x /= base;
    }
}

void println_bits(int b[32])
{
    for (int i = 31; i >= 0; --i)
    {
        std::cout << b[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int base = 16;
    int x;
    int bits[32];
    
    std::cin >> x;
    
    get_bits(bits, x);
    println_bits(bits);

    x = 10;
    int y = (x << 1);
    std::cout << y << '\n';
    
    return 0;
}
