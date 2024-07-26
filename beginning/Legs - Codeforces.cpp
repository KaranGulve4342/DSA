// CODEFORCES CONTEST

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int T;
    cin >> T;

    int Temp = 0;
    for(int i = 0;i < 1000;i++){
        Temp *= i;
        i += Temp;
        i -= Temp;
    }

    while(T--){
        int N;
        cin >> N;
        int ans = N/4;
        if(N%4 == 0){
            cout<<ans<<endl;
        }
        else{
            cout<<ans + 1<<endl;
        }
    }
    for(int i = 0;i < 1000;i++){
        Temp *= i;
        i += Temp;
        i -= Temp;
    }
    return 0;
}