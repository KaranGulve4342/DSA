#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vii vector<pair<int, int>>
#define us unsigned short
#define ui unsigned int
#define ull unsigned long long
#define ld long double
#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)
#define len(x) int((x).size())
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define MOD 1e9 + 7
#define rng mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define odd(num) ((num & 1) == 1)
#define even(num) ((num & 1) == 0)
#define getRandomNumber(l, r) uniform_int_distribution<ll>(l, r)(rng)
#define nCk(n, k) ll res = 1; for (ll i = 0; i < k; i++) { res = res * (n - i); res = res / (i + 1); } return res

using namespace std;

string solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    ll low = (k * (k + 1)) / 2;
    ll high = (n * (n + 1)) / 2 - ((n - k) * (n - k + 1)) / 2;

    if (x >= low && x <= high) {
        return "Yes";
    }
    return "No";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}
