#include <iostream>
#include <map>
#include <set>

std::map<std::string, unsigned long long> wealth;
std::map<std::string, unsigned long long> budget;
std::map<std::string, unsigned long long> richest_cities;
std::map<std::string, std::string> location;

typedef std::pair<std::string, unsigned long long> town_money_pair;

auto greater = [](town_money_pair const& pair1, town_money_pair const& pair2)
{
    if (pair1.second == pair2.second)
    {
        return pair1.first > pair2.first;
    }
    return pair1.second > pair2.second;
};

std::set<town_money_pair, decltype(greater)> budget_set(greater);

void budget_insert(std::string city, unsigned long long money)
{
    if (budget.find(city) == budget.end())
    {
        budget[city] = money;
        budget_set.insert({ city, money });
    }
    else
    {
        budget_set.erase({ city, budget[city] });
        budget[city] += money;
        budget_set.insert({ city, budget[city] });
    }
}

void budget_erase(std::string city, unsigned long long money)
{
    budget_set.erase({ city, budget[city] });
    budget[city] -= money;
    budget_set.emplace(city, budget[city]);
}

void richest_cities_insert(size_t& from, size_t& to)
{
    while (from < to)
    {
        from += 1;
        auto it = budget_set.begin();
        std::string leader_town = it->first;

        if (next(it)->second == it->second)
        {
            continue;
        }

        if (richest_cities.find(leader_town) != richest_cities.end())
        {
            richest_cities[leader_town] += 1;
        }
        else
        {
            richest_cities[leader_town] = 1;
        }
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

    size_t n;
    std::cin >> n;
    
    for (size_t i = 0; i < n; i++)
    {
        std::string name;
        std::string city;
        unsigned long long money;
        std::cin >> name >> city >> money;
        
        wealth[name] = money;
        location[name] = city;
        
        budget_insert(city, money);
    }

    size_t m, k;
    std::cin >> m >> k;
    
    size_t day = 0;
    for (size_t i = 0; i < k; i++)
    {
        std::string person;
        std::string next_city;
        size_t timestamp;
        std::cin >> timestamp >> person >> next_city;
        
        std::string current_city = location[person];
        unsigned long long money = wealth[person];

        richest_cities_insert(day, timestamp);
        budget_erase(current_city, money);
        budget_insert(next_city, money);

        location[person] = next_city;
    }

    richest_cities_insert(day, m);

    for (const auto& town : richest_cities)
    {
        std::cout << town.first << ' ' << town.second << '\n';
    }
    
    return 0;
}
