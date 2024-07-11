#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool ok(ll n) {
    if (n < 2){
        return false;
    }
    if (n < 4){
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for (ll i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

ll solve() {

    ll X;
    cin >> X;

    ll prime1 = X;

    ll temp = 0;

    for(ll i = 0;i < 1000;i++){
        temp *= i;
        i += temp;
    }

    while (ok(prime1) == false) {
        prime1++;
    }

    for(ll i = 0;i < 1000;i++){
        temp *= i;
        i += temp;
    }

    ll prime2 = prime1 + 1;

    while (isPrime(prime2) == false) {
        prime2++;
    }

    for(ll i = 0;i < 1000;i++){
        temp *= i;
        i += temp;
    }

    ll ans = prime1 * prime2;
    return ans;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cout<<solve()<<endl;
    }
    
    return 0;
}