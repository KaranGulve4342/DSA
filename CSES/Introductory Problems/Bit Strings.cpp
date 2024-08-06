// EVERY PROBLEM IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;


signed main(){
    int n;
    cin >> n;

    int ans = 1;

    // for(int i = 0;i < n;i++){
    //     ans = (ans * 2) % MOD;
    // }

    while(n--){
        ans = (ans << 1) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}