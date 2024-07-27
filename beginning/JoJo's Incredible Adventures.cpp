// CODEFORCES 1100 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(){
    string str;
    cin >> str;

    str += str;

    int n = str.length();
    int maxi = 0;
    int count = 0;

    for(int i = 0;i < n;i++){
        if(str[i] == '1'){
            count++;
        }
        else{
            count = 0;
        }
        maxi = max(maxi, count);
    }   

    if(maxi >= n/2){
        return (n/2)*(n/2);
    }

    int x, y;
    x = (maxi + 1)/2;
    y = (maxi + 2)/2;

    return x*y;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}