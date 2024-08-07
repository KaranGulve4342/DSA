// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int T;
    cin >> T;

    while(T--){
        int a, b;
        cin >> a >> b;

        if(((a+b)%3 == 0) && (2*a >= b) && (2*b >= a)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}