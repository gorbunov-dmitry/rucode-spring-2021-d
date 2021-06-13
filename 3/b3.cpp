#include <cmath>
#include <iostream>

long long dot(const std::pair<long long, long long>& a, const std::pair<long long, long long>& b)
{
    return a.first * b.first + a.second * b.second;
}

long double distance(const std::pair<long long, long long>& a, const std::pair<long long, long long>& b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    std::pair<long long, long long> p;
    std::pair<long long, long long> a;
    std::pair<long long, long long> b;
    std::cin >> p.first >> p.second >> a.first >> a.second >> b.first >> b.second;
    
    std::pair<long long, long long> ab(b.first - a.first, b.second - a.second);
    std::pair<long long, long long> ba(a.first - b.first, a.second - b.second);
    std::pair<long long, long long> ap(p.first - a.first, p.second - a.second);
    std::pair<long long, long long> bp(p.first - b.first, p.second - b.second);

    long double result;

    if (dot(ap, ab) <= 0)
    {
        result = distance(p, a);
    }
    else if (dot(bp, ba) <= 0)
    {
        result = distance(p, b);
    }
    else
    {
        long long dx_p_b = b.first - p.first;
        long long dy_p_b = b.second - p.second;
        long long dx_p_a = a.first - p.first;
        long long dy_p_a = a.second - p.second;
        result = (abs(dy_p_b * dx_p_a - dx_p_b * dy_p_a)) / distance(a, b);    
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(20);
    std::cout << result << '\n';

    return 0;
}
