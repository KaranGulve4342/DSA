// CODEFORCES 1200 RATED

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPossible(int x){
    cout<<"? "<<x<<" "<<x<<endl;

    int ans;
    cin >> ans;

    return x*x == ans;
}

void solve(){
    int lo = 2;
    int hi = 999;

    int ans = 999;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(isPossible(mid)){
            lo = mid + 1;
        }
        else{
            ans = mid;
            hi = mid - 1;
        }
    }
    cout<<"! "<<ans<<endl;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}