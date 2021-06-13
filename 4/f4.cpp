#include <cmath>
#include <iostream>
#include <map>

uint64_t pow(uint64_t value, uint64_t power, uint64_t module)
{
    uint64_t result = 1;

    for (uint64_t p = power; p; p >>= 1)
    {
        if (p & 1)
        {
            result = result * value % module;
        }
        value = value * value % module;
    }
    
    return result;
}

int main()
{
    uint64_t p, b, n;
    
    std::map<uint64_t, uint64_t> M;
    
    while (std::cin >> p >> b >> n)
    {
        M.clear();
        
        uint64_t bound = (uint64_t) sqrt(p);
        
        for (uint64_t i = 0; i < bound && i < p - 1; i++)
        {
            M[pow(b, i, p)] = i + 1;
        }

        bool solution_found = false;
        
        for (uint64_t i = 0; i < p - 1; i += bound)
        {
            uint64_t j = M[n * pow(b, p - 1 - i, p) % p];
            if (j)
            {
                std::cout << (i + j - 1) % (p - 1) << '\n';
                solution_found = true;
                break;
            }
        }

        if (!solution_found)
        {
            std::cout << "no solution\n";
        }
    }
    return 0;
}
