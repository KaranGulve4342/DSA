// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    string str;
    cin >> n;
    cin >> str;

    int l = 0;
    int r = n-1;

    while(l < r && str[l] != str[r]){
        l++;
        r--;
    }

    return r-l+1;
}

int main(){
    
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}