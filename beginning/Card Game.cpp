// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int score(int a, int b){
    if(a > b){
        return 1;
    }
    if(a < b){
        return -1;
    }
    return 0;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        vector<int> a(2);
        for(int i = 0; i < 2; i++){
            cin >> a[i];
        }
        vector<int> b(2);
        for(int i = 0; i < 2; i++){
            cin >> b[i];
        }
        int ans = 0;
        if(score(a[0], b[0]) + score(a[1], b[1]) > 0){
            ans++;
        }
        if(score(a[1], b[0]) + score(a[0], b[1]) > 0){
            ans++;
        }
        if(score(a[0], b[1]) + score(a[1], b[0]) > 0){
            ans++;
        }
        if(score(a[1], b[1]) + score(a[0], b[0]) > 0){
            ans++;
        }

        cout<<ans<<endl;
    }
    return 0;
}