// CODEFORCES

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll L, R;
    cin >> L >> R;
    if (r < L || R < l)
    {
        cout << 1 << endl;
        return;
    }
    vector<ll> rooms(101, 0);
    for (ll i = l; i <= r; i++)
    {
        rooms[i]++;
    }
    for (ll i = L; i <= R; i++)
    {
        rooms[i]++;
    }

    ll ans = 0;
    for (ll i = 1; i <= 100; i++){
        if (rooms[i] == 2 && rooms[i - 1] > 0)
        {
            ans++;
        }
        if (rooms[i] == 1 && rooms[i - 1] == 2)
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ll tt;
    cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}