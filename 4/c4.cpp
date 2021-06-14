#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    const int N = 1000001;
    vector<int> lp(N + 1);
    vector<int> pr;
    // vector<long long> a(1e12);

    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    int size = b - a + 1;
    vector<bool> is_primes(size, true);

    for (auto &p : pr)
    {

        long long k = max((long long)2, (a + p - 1) / p);
        while (k <= b / p)
        {
            long long ind = p * k - a;
            is_primes[ind] = false;
            k++;
        }
    }

    for (long long i = 0; i < is_primes.size(); i++)
    {
        if (is_primes[i])
        {
            if (i + a != 1)
                cout << i + a << " ";
        }
    }

    return 0;
}
