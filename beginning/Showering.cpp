// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

string solve(){
    int n, s, m;
    cin >> n >> s >> m;

    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    if(a[0].first >= s){
        return "YES";
    }
    if(m - a[n-1].second >= s){
        return "YES";
    }

    for(int i = 0;i + 1 < n;i++){
        int endTime = a[i].second;
        int nextTime = a[i+1].first;

        if(nextTime - endTime >= s){
            return "YES";
        }
    }

    return "NO";
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}