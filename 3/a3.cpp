#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    
    double x_a, y_a, x_b, y_b, x_c, y_c;
    std::cin >> x_a >> y_a >> x_b >> y_b >> x_c >> y_c;
    
    double dx_b_c = x_c - x_b;
    double dy_b_c = y_c - y_b;
    double dx_b_a = x_a - x_b;
    double dy_b_a = y_a - y_b;
    
    double scalar_mult = dx_b_c * dx_b_a + dy_b_c * dy_b_a;

    if (scalar_mult < 0)
    {
        std::cout << distance(x_a, y_a, x_b, y_b) << '\n';
        return 0;
    }
    
    double dx_a_c = x_c - x_a;
    double dy_a_c = y_c - y_a;
    double dx_a_b = x_b - x_a;
    double dy_a_b = y_b - y_a;
    
    double d = (abs(dy_a_c * dx_a_b - dx_a_c * dy_a_b)) / distance(x_b, y_b, x_c, y_c);
    std::cout << d << '\n';
    
    return 0;
}
