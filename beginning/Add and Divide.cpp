// CODEFORCES 1000 RATED 

#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define FOR(i, a, b) for (i = a; i < b; ++i)
#define rep(i, n) FOR(i, 0, n)
#define rev(i, n) for (i = n - 1; i >= 0; i--)
#define INF INT_MAX
#define pb push_back
#define tc  \
  int t;    \
  cin >> t; \
  while (t--)
#define ll long long int
#define mod (ll)(1e9 + 7)
#define vi vector<int>
#define vll vector<ll>
#define endl "\n"
#define si set<int>
using ld = long double;
#define ll long long int
int main()
{
  fastio;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  tc
  {
    ll a, b, ans = 1e18, count;
    cin >> a >> b;
    for (ll i = 0; i * i <= a; i++)
    {
      if (b == 1 and i == 0)
        continue;
      count = i;

      ll c = a;
      //count=0;
      while (c)
      {
        c /= (b + i);
        count++;
      }
      ans = min(ans, count);
    }
    cout << ans << endl;
  }
  return 0;
}