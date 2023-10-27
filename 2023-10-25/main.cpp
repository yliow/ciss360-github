#include <iostream>
#include <vector>

std::vector< int > bits(uint32_t x)
{
    std::vector< int > ret(32, 0);
    for (int i = 0; i < 32; ++i)
    {
        ret[i] = x % 2;
        x /= 2;
    }
    return ret;
}

int main()
{
    std::cout << sizeof(int) << '\n';
    uint32_t x = 129;
    std::vector< int > b = bits(x);

    for (int i = 31; i >= 0; i--)
    {
        std::cout << b[i];
    }
    std::cout << '\n';
    return 0;
}
