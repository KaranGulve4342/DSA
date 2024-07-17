// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string str;
    cin >> n >> str;

    int open = 0;
    int close = 0;
    int operations = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == '('){
            open++;
        } 
        else {
            close++;
        }

        if(close > open){
            close--;
            operations++;
        }
    }
    cout<<operations<<endl;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }
}