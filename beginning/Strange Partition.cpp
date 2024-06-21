// CODEFORCES 900 RATED

#include <bits/stdc++.h>
#define vll vector<long long>
#define ll long long
#define all(x) x.begin(), x.end()
#define sp ' '
#define nl '\n'
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,x;
        cin>>n>>x;
    
        vll arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
    
        ll sum = accumulate(all(arr), 0LL);
        ll bmin = sum/x + (sum%x != 0);
    
        ll bmax = 0;
        for(auto a:arr){
            bmax = bmax + a/x + (a%x != 0);
        }
    
        cout<<bmin<<sp<<bmax<<nl;
    }

    return 0;
}