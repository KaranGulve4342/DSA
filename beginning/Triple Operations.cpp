// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int calculate(int n){
    if(n < 3){
        return 1;
    }
    return 1 + calculate(n/3);
}

signed main(){
    int T;
    cin >> T;

    vector<int> prefix(3000001, 0);
    prefix[1] = 1;
    for(int i = 2;i < 3000001;i++){
        prefix[i] = prefix[i-1] + calculate(i);
    }

    while(T--){
        int l, r;
        cin >> l >> r;

        int ans = 2*calculate(l) + prefix[r] - prefix[l];

        cout<<ans<<endl;
    }

    return 0;
}