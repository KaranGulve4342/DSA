// CODEFORCES 800 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    string str;
    cin >> str;

    str = 'a' + str;
    int n = str.length();
    int count = 0;

    for(int i = 0;i < n-1;i++){
        count += min(abs(str[i] - str[i+1]), 26 - abs(str[i] - str[i+1]));
    }

    cout<<count<<endl;
    return 0;

}