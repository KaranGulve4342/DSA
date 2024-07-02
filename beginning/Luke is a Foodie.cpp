// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
#include <math.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
# define M_PI  3.14159265358979323846
    
long long M=1e9+7;
long long mod(long long x){
    return ((x%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}

void solve (){
    ll n,x;
    cin>>n>>x;
    ll total=0,l=-1,r=1e9+5;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(a+x<l || a-x>r){
            total++;
            l = a-x, r = a+x;
        }
        else{
            l = max(l, a-x);
            r = min(r, a+x);
        }
    }
    cout<<total<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}