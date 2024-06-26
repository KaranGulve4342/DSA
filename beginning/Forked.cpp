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

	int t = 1;
	cin >> t;
	while (t--){
		int a,b;
		cin>>a>>b;

		int xk, yk;
		cin>>xk>>yk;

		int xq, yq;
		cin>>xq>>yq;


		vii directions = {{a,b}, {a, -b}, {-a, b}, {-a, -b},
						  {b,a}, {b, -a}, {-b, a}, {-b, -a}};

		//Attacking positions for king, queen
		set<pii> st1, st2;
		for(auto d: directions){
			int x = xk + d.first;
			int y = yk + d.second;
			st1.insert({x,y});

			x = xq + d.first;
			y = yq + d.second;
			st2.insert({x,y});
		}
		
		int ans = 0;
		//Attacking positions for queen
		for(auto pos: st1){

			if(st2.find(pos) != st2.end())
				ans++;
		}
		cout<<ans<<nl;
		
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}