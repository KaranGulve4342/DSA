// CODEFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

#define int long long

string solve(){
    set<char> st;
    string s;
    cin >> s;

    for(int i = 0;i < s.size();i++){
        st.insert(s[i]);
    }

    int flag = true;

    for(int i = 0;i < s.length();i++){
        if(s[i] != s[i % (int)st.size()]){
            flag = false;
        }
    }

    return flag ? "YES" : "NO";
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
}