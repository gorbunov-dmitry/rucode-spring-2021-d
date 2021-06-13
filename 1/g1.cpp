#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

bool less(std::pair<int, int> p1, std::pair<int, int> p2)
{
    return p1.first < p2.first;
}

bool greater(std::pair<int, int> p1, std::pair<int, int> p2)
{
    return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
}

int main()
{
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

    unsigned int n, m;
    std::cin >> n >> m;

    std::vector<int> adds_length;
    std::vector<int> adds_inedxes;

    std::set<std::pair<int, int>, decltype(&greater)> intervals_length(greater);
    std::set<std::pair<int, int>, decltype(&less)> intervals_indexes(less);

    intervals_length.emplace(n, 1);
    intervals_indexes.emplace(1, n);
    
    for (size_t i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        
        if (x > 0)
        {
            auto it = intervals_length.begin();
            if (it != intervals_length.end() && it->first >= x)
            {
                std::pair<int, int> interval = (*it);
                intervals_length.erase(it);
                auto it = intervals_indexes.lower_bound({ interval.second, interval.first });
                intervals_indexes.erase(it);
                if (interval.first != x)
                {
                    intervals_length.emplace(interval.first - x, interval.second + x);
                    intervals_indexes.emplace(interval.second + x, interval.first - x);
                }
                std::cout << interval.second << '\n';
                adds_inedxes.push_back(interval.second);
                adds_length.push_back(x);
            }
            else
            {
                std::cout << -1 << '\n';
                adds_inedxes.push_back(-1);
                adds_length.push_back(-1);
            }
        }
        else
        {
            x = -x - 1;
            if (x < adds_inedxes.size() && adds_inedxes[x] > 0)
            {
                std::pair<int, int> adds = { adds_length[x], adds_inedxes[x] };
                
                intervals_indexes.emplace(adds.second, adds.first);
                intervals_length.emplace(adds.first, adds.second);
                
                auto it = intervals_indexes.lower_bound({ adds_inedxes[x], 0 });
                auto right = next(it);
                auto left = prev(it);
                
                if (left != intervals_indexes.end() && left->first + left->second == it->first)
                {
                    intervals_length.erase({ it->second,it->first });
                    intervals_length.erase({ left->second,left->first });
                    
                    adds.first = left->second + it->second;
                    adds.second = left->first;
                    
                    intervals_indexes.erase(left);
                    intervals_indexes.erase(it);
                    
                    intervals_indexes.emplace(adds.second, adds.first);
                    intervals_length.emplace(adds.first, adds.second);
                }
                
                it = intervals_indexes.lower_bound({ adds.second, adds.first });
                
                if (right != intervals_indexes.end() && it->first + it->second == right->first)
                {
                    intervals_length.erase({ it->second,it->first });
                    intervals_length.erase({ right->second,right->first });
                    
                    adds.first = right->second + it->second;
                    
                    intervals_indexes.erase(right);
                    intervals_indexes.erase(it);
                    
                    intervals_indexes.emplace(adds.second, adds.first);
                    intervals_length.emplace(adds.first, adds.second);
                }

            }
            adds_inedxes.push_back(-1);
            adds_length.push_back(-1);
        }
    }

    return 0;
}
