#include <iostream>
#include <vector>

int main() {
    const int MOD = (int) 1e9 + 7;
    
    std::string sequence;
    std::cin >> sequence;

    const int SIZE = sequence.size() + 2;
    
    std::vector<std::vector<int>> v(SIZE, std::vector<int>(SIZE));
    
    v[0][0] = 1;
    for (size_t i = 1; i <= sequence.size(); i++)
    {
        v[i][0] = v[i - 1][1];
        for (size_t j = 1; j <= sequence.size(); j++)
        {
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j + 1]) % MOD;
        }
    }
    
    int depth = 0;
    int result = 1;
    
    for (size_t i = 0; i < sequence.size(); i++)
    {
        if (sequence[i] == '(')
        {
            ++depth;
        }
        else
        {
            result = (result + v[sequence.size() - i - 1][depth + 1]) % MOD;
            --depth;
        }
    }
    
    std::cout << result;
    
    return 0;
}
