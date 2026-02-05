#include <iostream>
#include <cmath>

int main()
{
    float f;
    unsigned int * x = (unsigned int *)(&f);
    (*x) = (1 << 31)
        | (0x7e << 23)
        | (1 << 21);
    std::cout << f << '\n';

    *x = rand();
    std::cout << f << '\n';

    (*x) = (0 << 31)
        | (0xff << 23)
        | (0 << 21);
    std::cout << f << '\n';
    (*x) = (1 << 31)
        | (0xff << 23)
        | (0 << 21);
    std::cout << f << '\n';
    (*x) = (1 << 31)
        | (0xff << 23)
        | (1 << 21);
    std::cout << f << '\n';

    std::cout << "---\n";
    f = 0.0;
    std::cout << f << '\n';
    f = -0.0;
    std::cout << f << '\n';
    f = sqrt(-1.0);
    std::cout << f << '\n';
    f = 0.0f / 0.0f;
    std::cout << f << '\n';
    f = log10(-1.0);
    std::cout << f << '\n';
    f = 0.0f/0.0f + 1;
    std::cout << f << '\n';
    std::cout << std::isnan(f) << '\n';

    std::cout << "---\n";
    f = 1.0f / 0.0f;
    std::cout << f << '\n';
    f = -1.0f / 0.0f;
    std::cout << f << '\n';
    f = 1.0f / -0.0f;
    std::cout << f << '\n';
    f = -1.0f / -0.0f;
    std::cout << f << '\n';
    f = log10(0.0);
    std::cout << f << '\n';
    std::cout << std::isinf(f) << '\n';
    std::cout << (1.0 / 0.0 == 2.0 / 0.0) << '\n';
    std::cout << (-1.0 / 0.0 == 2.0 / -0.0) << '\n';
    std::cout << (1.0 < 1.0 / 0.0) << '\n';
    std::cout << (-1.0 / 0.0 < 1.0) << '\n';

    std::cout << 1e1000f << '\n';
    std::cout << -1e1000f << '\n';
    std::cout << 1e-1000f << '\n';
    std::cout << -1e-1000f << '\n';

    
    return 0;
}
