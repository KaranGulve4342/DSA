// CODEFORCES 1100 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    string t;
    cin >> t;

    for(int i = 0;i < n;i++){
        if(s[i] == '1'){
            return "YES";
        }
        else if(s[i] != t[i]){
            return "NO";
        }
    }

    return "YES";
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}