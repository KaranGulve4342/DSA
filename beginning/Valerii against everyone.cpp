// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    unordered_map<int, int> mp;
    cin >> n;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto x : mp){
        if(x.second > 1){
            return "YES";
        }
    }
    return "NO";
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
}