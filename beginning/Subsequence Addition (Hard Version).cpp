// CODEFORCES 1100 RATED

#include<bits/stdc++.h>
using namespace std;

#define int long long

string solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int sum = 0;


    for(int i = 0;i < n;i++){
        if(v[i] == 1){
            sum += v[i];
            continue;
        }
        if(sum < v[i]){
            return "NO";
        }
        sum += v[i];
    }

    return "YES";
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}