#include <iostream>

int AND(int x, int y)
{
    if (x == 0 && y == 0) return 0;
    else if (x == 0 && y == 1) return 0;
    else if (x == 1 && y == 0) return 0;
    else return 1;
}

int OR(int x, int y)
{
    if (x == 0 && y == 0) return 0;
    else if (x == 0 && y == 1) return 1;
    else if (x == 1 && y == 0) return 1;
    else return 1;
}

int NOT(int x)
{
    if (x == 0) return 1;
    else return 0;
}

int XOR(int x, int y) // using only AND, OR, NOT
{
    return OR(AND(x, NOT(y)), AND(NOT(x), y));
}

void HA(int x, int y, int * s, int * c)
{
    *s = XOR(x, y);
    *c = AND(x, y);
}

int main()
{
    std::cout << "XOR\n";
    std::cout << "0 0: " << XOR(0, 0) << '\n';
    std::cout << "0 1: " << XOR(0, 1) << '\n';
    std::cout << "1 0: " << XOR(1, 0) << '\n';
    std::cout << "1 1: " << XOR(1, 1) << '\n';
    
    std::cout << "HA\n";
    int s, c;
    HA(0, 0, &s, &c);
    std::cout << "0 0: " << s << ' ' << c << '\n';
    HA(0, 1, &s, &c);
    std::cout << "0 1: " << s << ' ' << c << '\n';
    HA(1, 0, &s, &c);
    std::cout << "1 0: " << s << ' ' << c << '\n';
    HA(1, 1, &s, &c);
    std::cout << "1 1: " << s << ' ' << c << '\n';

    return 0;
}
