// CODEFORCES 1200 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        int res = 2;

        cin >> n;

        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        while(true){
            unordered_set<int> s;
            for(int i = 0; i < n; i++){
                s.insert(v[i] % res);
            }
            if(s.size() == 2){
                break;
            }
            res *= 2;
        }

        cout<<res<<endl;
    }
}