#include <bits/stdc++.h>
using namespace std;

const int M = 2e6+7;

void generatePrimes(vector<int> &primes) {
    vector<bool> is_prime(M, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < M; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < M; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primes;
    generatePrimes(primes);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto it1 = upper_bound(primes.begin(), primes.end(), n);
        auto it2 = lower_bound(primes.begin(), primes.end(), n + *it1);
        cout << (*it1) * (*it2) << "\n";
    }

    return 0;
}
