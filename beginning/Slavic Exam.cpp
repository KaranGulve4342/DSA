// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;
    string t;
    cin >> s;
    cin >> t;

    int n = s.length();
    int m = t.length();

    int i = 0;
    int j = 0;

    while(i<n && j<m){
 
        if(s[i]=='?'){
            s[i]=t[j];
        }
 
        if(s[i]==t[j]){
            i++;
            j++;
            continue;
        }
        i++;
    }

    if(j < m){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

    for(auto &x : s){
        if(x=='?'){
            x='a';
        }
    }
    cout<<s<<endl;
    return;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}

