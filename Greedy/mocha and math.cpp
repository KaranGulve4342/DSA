// CODEFORCES 900 RATED

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
#define yes "Yes"
#define nope "No"

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

	vi arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int ans = accumulate(arr.begin(), arr.end(), arr[0], std::bit_and<int>());
	cout<<ans<<nl;




}

/*Mocha and Math
Aim: Minimize the maximum value
[l, r] op: bitwise-&
1 & 0 -> 0
0 & 1 -> 0
0 & 0 -> 0
1 & 1 -> 1

a1&a2&a3&a4 <= min(a1,a2,a3,a4)
101010
111111
101000

a1&a2&a3&a4...an
somehow if I can get this -> &1...n


arr: 	a1 a2 a3 a4
l=1,r=4 &14 &23 &23 &14
l=1,r=2 &1234 &1234 &1234 &1234
you have minimized the maximum value

*/

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin>>t;
	while(t--)
		solve();
}