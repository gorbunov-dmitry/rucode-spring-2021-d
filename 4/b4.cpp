#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(5);
    int n;
    cin >> n;
    int mind[n + 1];
    mind[0] = 0;
    vector<int> primes;
    for (int i = 1; i < n + 1; ++i){
        mind[i] = i;
    }
    for (int x = 2; x < n + 1; ++x){
        if (mind[x] == x){
            primes.push_back(x);
        }
        for (int i = 0; i < primes.size(); ++i){
            int p = primes[i];
            if (x * p > n || mind[x] < p){
                break;
            }
            mind[x * p] = p;
        }
    }
    primes.clear();
    primes.shrink_to_fit();
    unsigned short cnt[n + 1];
    cnt[0] = 0;
    for (int i = 1; i < n + 1; ++i){
        if (mind[i] == i){
            cnt[i] = 1;
        }
        else{
            if (mind[i] == mind[i / mind[i]]){
                cnt[i] = cnt[i / mind[i]];
            }
            else{
                cnt[i] = 1 + cnt[i / mind[i]];
            }
        }
    }
    for (int i = 1; i < n + 1; ++i){
        if (cnt[i] >= 3){
            cout << i << ' ';
        }
    }
    return 0;
}
