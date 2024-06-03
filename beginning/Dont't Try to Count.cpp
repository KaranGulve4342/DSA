// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve() {
    ll n,m,cnt=6,flag=0,res=0;
    string x,s;
    cin>>n>>m;
    cin>>x>>s;
    while(cnt--) {
        if(x.find(s) != string::npos) {
            flag=1;
            break;
        }
        res++;
        x+=x;
    }
    if(flag) return res;
    return -1; 
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }

    return 0;
}
