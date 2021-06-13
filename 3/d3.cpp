#include <iostream>
#include <vector>

struct Point
{
    long long x;
    long long y;
    Point(long long x = 0, long long y = 0) : x(x), y(y) {}
};

std::istream& operator >> (std::istream& is, Point& point)
{
    return is >> point.x >> point.y;
}

long long cross_product(const Point& a, const Point& b)
{
    return (a.x - b.x) * (a.y + b.y);
}

template <class T>
std::istream& operator >> (std::istream& is, std::vector<T>& v)
{
    for (auto& item : v)
    {
        is >> item;
    }
    return is;
}

int main()
{
    size_t n;
    std::cin >> n;
    
    std::vector<Point> points(n);
    std::cin >> points;
    
    long long square = 0;
    for (size_t i = 0; i < n; i++)
    {
        square += cross_product(points[i], points[(i + 1) % n]);
    }
    
    std::cout << abs(square) / 2.0;
}
