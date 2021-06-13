#include <iostream>
#include <numeric>
#include <vector>

std::vector<std::vector<size_t>> calculate_binomial_coefficients(size_t size)
{
    std::vector<std::vector<size_t>> coefficients(size + 1, std::vector<size_t>(size + 1));
    coefficients[0][0] = 1;
    for (size_t i = 1; i <= size; i++)
    {
        coefficients[i][0] = 1;
        for (size_t j = 1; j <= size; j++)
        {
            coefficients[i][j] = coefficients[i - 1][j] + coefficients[i - 1][j - 1];
        }
    }
    return coefficients;
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    for (const auto& item : v)
    {
        os << item << ' ';
    }
    return os;
}

int main()
{
    size_t n, k, p;
    std::cin >> n >> k >> p;

    std::vector<std::vector<size_t>> binomial_coefficients = calculate_binomial_coefficients(n + 1);
    
    std::vector<size_t> a(n);
    std::iota(a.begin(), a.end(), 1);
    
    size_t bound = 0;
    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (a[j] > bound)
            {
                size_t binomial_coefficient = binomial_coefficients[n - a[j]][k - i - 1];
                if (p < binomial_coefficient)
                {
                    a[i] = a[j];
                    bound = a[i];
                    break;
                }
                else
                {
                    p -= binomial_coefficient;
                }
            }
        }
    }
    
    a.resize(k);
    
    std::cout << a << '\n';
    
    return 0;
}
