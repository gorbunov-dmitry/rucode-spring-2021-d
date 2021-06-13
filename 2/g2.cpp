#include <iostream>
#include <vector>

int main() {
    unsigned long n, k;
    std::cin >> n >> k;

    std::vector<unsigned long> fib(n + 1);
    fib[0] = 1;
    fib[1] = 2;
    for (auto it = fib.begin() + 2; it < fib.end(); it++)
    {
        *it = *(it - 1) + *(it - 2);
    }
    
    unsigned long prev = 0;
    for (auto it = fib.rbegin() + 1; it != fib.rend(); it++)
    {
        if (prev == 1)
        {
            std::cout << 0;
            prev = 0;
        }
        else if (*it <= k)
        {
            std::cout << 1;
            k -= *it;
            prev = 1;
        }
        else
        {
            std::cout << 0;
            prev = 0;
        }

    }
    return 0;
}
