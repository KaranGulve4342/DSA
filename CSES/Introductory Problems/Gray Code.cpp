// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    for(int i = 0;i < (1 << n);i++){
        int val = i ^ (i >> 1);
        bitset<32> r(val);
        string str = r.to_string();
        cout<<str.substr(32-n)<<endl;
    }

    return 0;
}