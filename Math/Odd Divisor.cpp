// CODEFORCES 900 RATED

#include <bits/stdc++.h>

#define ll long long
#define nl '\n'

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        ll n;
        cin>>n;
    
        if((n&(n-1)) == 0)cout<<"No"<<nl;
        else cout<<"Yes"<<nl;
    }
    return 0;
}