#include <iostream>

long long gcd_extended(const long long& a, const long long& b, long long& x, long long& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    
    long long x1;
    long long y1;
    
    long long d = gcd_extended(b % a, a, x1, y1);
    
    x = y1 - (b / a) * x1;
    y = x1;
    
    return d;
}

int main()
{
    long long a, b, n, m;
    std::cin >> a >> b >> n >> m;

    long long x, y;
    gcd_extended(m, n, x, y);
    
    x = (x % n + n) % n;
    y = (y % m + m) % m;
    
    std::cout << (a * m * x + b * n * y) % (m * n) << '\n';

    return 0;
}
