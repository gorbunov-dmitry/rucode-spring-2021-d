#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct line_y
{
    line_y
    (
        long long id,
        long long y1,
        long long y2
    ) : 
        id(id), 
        y1(y1), 
        y2(y2) 
    {
    }
    long long id;
    long long y1;
    long long y2;
};

bool compare_by_y(const line_y& line1, const line_y& line2)
{
    return line1.y1 > line2.y1;
}

struct line_x : public line_y
{
    line_x
    (
        long long id,
        long long x,
        long long y1,
        long long y2,
        bool closed
    ) : 
        line_y(id, y1, y2),
        x(x),
        closed(closed)
    {
    }
    long long x;
    bool closed;
};

bool compare_by_x(const line_x& line1, const line_x& line2)
{
    return line1.x < line2.x || (line1.x == line2.x && line1.id < line2.id);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::set<line_x, decltype(&compare_by_x)> x_lines(compare_by_x);
    std::set<line_y, decltype(&compare_by_y)> y_lines(compare_by_y);
    
    for (size_t i = 0; i < n; i++)
    {
        long long x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        
        if (x1 > x2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
        if (y1 > y2)
        {
            std::swap(y1, y2);
        }
        
        x_lines.emplace(i, x1, y1, y2, false);
        x_lines.emplace(i, x2, y1, y2, true);
    }

    size_t result = 0;
    for (const auto& x_line : x_lines)
    {
        if (y_lines.empty())
        {
            y_lines.emplace(x_line.id, x_line.y1, x_line.y2);
        }
        else
        {
            line_y y_line = { x_line.id, x_line.y1, x_line.y2 };
            auto it = y_lines.lower_bound(y_line);
            
            if (it == y_lines.end() || it->y2 < y_line.y2)
            {
                y_lines.insert(y_line);
            }
            else if (it->id == y_line.id)
            {
                result++;
                y_lines.erase(it);
            }
        }
    }
    
    std::cout << result;
    
    return 0;
}
