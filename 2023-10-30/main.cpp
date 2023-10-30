#include <iostream>
#include <vector>

std::vector< int > bits(uint32_t x, int base=2)
{
    std::vector< int > ret(32, 0);
    for (int i = 0; i < 32; ++i)
    {
        ret[i] = x % base;
        x /= base;
    }
    return ret;
}

std::vector< int > betterbits(uint32_t x)
{
    std::vector< int > ret(32, 0);
    for (int i = 0; i < 32; ++i)
    {
        ret[i] = x & 1;
        x >>= 1;
    }
    return ret;
}

void printlnbits(uint32_t x)
{
    for (int i = 31; i >= 0; i--)
    {
        std::cout << ((x >> i) & 1);
    }
    std::cout << '\n';
}

void turn_on(uint32_t * r, int index)
{
    (*r) |= (1 << index);
}

void turn_off(uint32_t * r, int index)
{
    (*r) &= ~(1 << index);    
}

void toggle(uint32_t * r, int index)
{
    (*r) ^= (1 << index); 
}

int main()
{
    std::cout << sizeof(int) << '\n';
    uint32_t x = 129;
    std::vector< int > b = bits(x);

    printlnbits(x);

    std::vector< int > c = bits(x, 4);
    for (int i = 31; i >= 0; i--)
    {
        std::cout << c[i];
    }
    std::cout << '\n';

    uint32_t r0 = 1;
    std::cout << r0 << '\n';
    r0 = (r0 << 1);
    std::cout << r0 << '\n';
    r0 = (r0 << 1);
    std::cout << r0 << '\n';
    r0 = (r0 << 2);
    std::cout << r0 << '\n';

    std::cout << 17 << '\n';
    std::cout << 2 * 17 << '\n';
    std::cout << (17 << 1) << '\n';

    uint32_t r1 = (7 >> 1);
    std::cout << r1 << '\n';

    uint32_t r2 = 0xc; // 0b1100; // (1 << 3) | (1 << 2); // 12
    uint32_t r3 = 1; // 1
    uint32_t r4 = r2 | r3;
    std::cout << r4 << '\n';

    std::cout << (10 & 3) << '\n';
    
    std::cout << (15 ^ 3) << '\n'; 

    uint32_t r5 = 42;
    uint32_t r6 = ~r5;
    std::vector< int > bits_r5 = bits(r5);
    std::vector< int > bits_r6 = bits(r6);

    for (int i = 31; i >= 0; i--)
    {
        std::cout << bits_r5[i];
    }
    std::cout << '\n';
    for (int i = 31; i >= 0; i--)
    {
        std::cout << bits_r6[i];
    }
    std::cout << '\n';

    std::cout << "\n testing \n";
    printlnbits(r5);
    turn_on(&r5, 5);
    printlnbits(r5);
    turn_on(&r5, 4);
    printlnbits(r5);

    std::cout << "testing turn off\n";
    turn_off(&r5, 5);
    printlnbits(r5);

    turn_off(&r5, 2);
    printlnbits(r5);

    std::cout << "testing toggle\n";
    toggle(&r5, 2);
    printlnbits(r5);
    toggle(&r5, 3);
    printlnbits(r5);
    
    return 0;
}
