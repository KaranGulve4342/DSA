//CODEFORCES 1100 RATED

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const ll mod = 1e9+7;
int main()
{   
    ios;
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("/Users/sreejith/Desktop/output.txt", "w", stdout);
    #endif
    
    ll t;
    cin>>t;
    while(t--) {
        ll n,ans = 1;
        cin>>n;
        vector < ll > a(n),b(n),res(n);
        for(ll i = 0 ; i < n ; i++) {
            cin>>a[i];
        }
        for(ll i = 0 ; i < n ; i++) {
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        sort(a.begin(),a.end());
        ll j = 0;
        for(ll i = 0 ; i < n ; i++) {
            while(a[j] <= b[i] and j!=n) {
                j++;
            }
            if(j!=n)
                res[i] = n-j;
        }
        
        sort(res.begin(),res.end());
        for(ll i = 0 ; i < (ll)res.size() ; i++) {
            ans = ((ans%mod)*((res[i]-i)%mod))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;     
 }        