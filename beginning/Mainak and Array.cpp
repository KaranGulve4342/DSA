#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

// find_by_order, order_of_key: 0 indexed
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

// Types
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

// Utils
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

// Constants
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Helper Functions
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
ll nCk(ll n, ll k)
{
	ll res = 1;
	for (ll i = 0; i < k; i++)
	{
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}

/*----------------------------------------------------------------------------*/



void solve(){
	int n;
	cin>>n;

	vi arr(n+1);
	for(int i=1; i<=n; i++)
		cin>>arr[i];

	int maxi = arr[n]-arr[1];
	//fix arr[n]
	for(int i=1; i<=n-1; i++){
		maxi = max(maxi, arr[n]-arr[i]);
	}

	//fix arr[1]
	for(int i=2; i<=n; i++){
		maxi = max(maxi, arr[i] - arr[1]);
	}

	//pick entire array as a sub-segment
	for(int i=1; i<=n-1; i++)
		maxi = max(maxi, arr[i] - arr[i+1]);

	cout<<maxi<<nl;


}

/*Mainak and Array
Aim: Maximize arr[n] - arr[1]
ops: cylically rotate it by any amount (ACW)


1 3 9 11 5 7
3 9 11 5 7 1 K=1
9 11 5 7 1 3 K=2
11 5 7 1 3 9 K=3

Think: what values can come in 1st and nth position
candidate = arr[n] - arr[1]

if you want to change values at 1st, and nth position
1. only include a1 -> change values at 1st pos; arr[n] fixed
2. only include an -> change values at nth pos; arr[1] fixed
3. include both a1 and an

1. arr[n] - {a1, a2, a3...an-1}
2. {a2, a3, ..an} - arr[1]
3. arr[i] - arr[i+1] i=1..n-1
O(n)


n=5
a1 a2 a3 a4 a5
a2 a3 a4 a5 a1 K=1 a1 - a2
a3 a4 a5 a1 a2 K=2 a2 - a3
a4 a5 a1 a2 a3 K=3 a3 - a4
a5 a1 a2 a3 a4 K=4 a4 - a5
a1 a2 a3 a4 a5

arr[i] - arr[i+1]




*/

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin>>t;
	while(t--)
		solve();
}