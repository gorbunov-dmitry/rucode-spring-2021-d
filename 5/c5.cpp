#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

std::vector<int> x;
std::vector<int> y;

int distance(size_t i, size_t j)
{
    return (int) (pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
}

int main()
{
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    x.resize(n);
    y.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x[i] >> y[i];
    }

    std::vector<bool> used(n, false);
    std::vector<int> min_e(n, INT_MAX);
    std::vector<int> end_e(n, -1);
    
    min_e[1] = 0;
    
    double result = 0;

    for (size_t i = 0; i < n; i++)
    {
        int v = -1;
        for (size_t j = 0; j < n; j++)
        {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
            {
                v = j;
            }
        }
        used[v] = true;
        if (end_e[v] != -1)
        {
            result += sqrt(distance(v, end_e[v]));
        }
        for (size_t to = 0; to < n; to++)
        {
            int d = distance(v, to);
            if (!used[to] && (d < min_e[to]))
            {
                min_e[to] = d;
                end_e[to] = v;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(10) << result << '\n';
    
    return 0;
}