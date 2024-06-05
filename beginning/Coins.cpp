// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;
#define ll long long
string solve(){
    ll n,k;
    cin>>n>>k;
    if (!(n&1)) return "YES";
    else if(n&1 && k&1) return "YES";
    else return "NO";
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}