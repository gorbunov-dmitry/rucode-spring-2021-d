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

Point operator - (const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y);
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
    
    unsigned int positive = 0;
    unsigned int negative = 0;
    
    for (size_t i = 0; i < n; i++)
    {
        long long cp = cross_product(points[(i + 1) % n] - points[i], points[i] - points[(i - 1 + n) % n]);
        
        if (cp > 0)
        {
            positive++;
        }
        if (cp < 0)
        {
            negative++;
        }
    }

    std::string result = "YES";
    if (positive && negative)
    {
        result = "NO";
    }
    std::cout << result << '\n';
}
