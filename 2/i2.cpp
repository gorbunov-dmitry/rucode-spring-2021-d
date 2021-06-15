#include <cmath>
#include <iostream>
#include <string>
#include <vector>

long long C(long long n, long long k)
{
    if (k == n || k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return n;
    }
    return C(n - 1, k) + C(n - 1, k - 1);
}

long long char_to_digit(char symbol)
{
    return (long long) symbol - (long long) '0';
}

int main()
{
    long long int n, k;
    std::cin >> n >> k;
    
    if (k == 1)
    {
        std::cout << 1 << '\n';
        return 0;
    }

    std::vector<long long> result;
    
    std::string string = std::to_string(n);
    
    int flag = 0;
    
    for (size_t i = 0; i < string.length(); i++)
    {
        int start = i == 0 ? 1 : -1;
        for (int j = start; j < 11; j++)
        {
            result.push_back(j);
            
            long long sum = 0;
            for (auto digit : result)
            {
                sum = sum * 10 + digit;
            }
            
            if (sum > n)
            {
                result.pop_back();
                break;
            }
            
            int counter = 0;
            
            for (size_t s = 0; s <= i; s++)
            {
                if (result[s] == char_to_digit(string[s]) || result[s] == -1)
                {
                    counter++;
                    continue;
                }
                if (result[s] < char_to_digit(string[s]))
                {
                    flag = 1;
                    break;
                }
                if (result[s] > char_to_digit(string[s]))
                {
                    flag = 2;
                    break;
                }
            }
            
            if (counter == i + 1)
            {
                flag = 0;
            }
            
            result.pop_back();
            
            int t = string.length() - i - 1;
            
            if (flag == 1)
            {
                int kol = 1;
                for (int y = 1; y <= t; ++y)
                {
                    kol += pow(10, y);
                }
                if (j == -1)
                {
                    kol = 1;
                }
                if (kol >= k)
                {
                    result.push_back(j);
                    break;
                }
                else
                {
                    k -= kol;
                }
            }

            int kol = 1;
            for (int y = 1; y < t; ++y)
            {
                kol += pow(10, y);
            }

            if (flag == 0)
            {
                kol += n % int(pow(10, t)) + 1;
                if (j == -1)
                {
                    kol = 1;
                }
                if (kol >= k)
                {
                    result.push_back(j);
                    break;
                }
                else
                {
                    k -= kol;
                }
            }

            if (flag == 2)
            {
                if (j == -1)
                {
                    kol = 1;
                }
                if (kol >= k)
                {
                    result.push_back(j);
                    break;
                }
                else
                {
                    k -= kol;
                }
            }
        }
    }

    for (auto item : result)
    {
        if (item == -1)
        {
            break;
        }
        std::cout << item;
    }
    
    return 0;
}
