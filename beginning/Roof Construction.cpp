// CODEFORCES 1000 RATED

#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;

    ll t = 1;
    while(t <= n-1){
        t*=2;
    }
    t/=2;

    for(ll i = n-1;i >= t;i--){
        cout << i << " ";
    }

    for(ll i = 0;i < t;i++){
        cout << i << " ";
    }
    cout<<endl;
}

int main(){
    ll T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}