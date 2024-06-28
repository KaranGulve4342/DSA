// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;

    vector<ll> divisors;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(i != n / i){
                divisors.push_back(n / i);
            }
        }
    }

    ll a = 1;
    ll b = n-1;
    ll ans = __lcm(a, b);

    for(auto el : divisors){
        ll sec = n/el;
        ll tempa = el*1;
        ll tempb = el*(sec - 1);

        ll tempans = __lcm(tempa, tempb);

        if(tempans < ans){
            ans = tempans;
            a = tempa;
            b = tempb;
        }
    }

    cout<<a<<" "<<b<<endl;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }
    return 0;
}