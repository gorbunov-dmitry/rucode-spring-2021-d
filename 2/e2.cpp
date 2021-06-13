#include <iostream>

const size_t MAX_N = 40;

int addends[MAX_N];

void generate_addends(int number, int max, int position = 0)
{
    if (!number)
    {
        for (int i = 0; i < position; i++)
        {
            std::cout << addends[i] << ' ';
        }
        std::cout << '\n';
    }
    for (int i = 1; i <= std::min(max, number); i++)
    {
        addends[position] = i;
        generate_addends(number - i, i, position + 1);
    }
}

int main()
{
    int n;
    std::cin >> n;
    
    generate_addends(n, n);
    
    return 0;
}
