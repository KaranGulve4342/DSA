// EVERY PROBLEM IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

int solve(int k){
    int n = k*k;

    int totalWays = n*(n-1)/2;

    int attackingWays = 4 * (k-1) * (k-2);

    return totalWays - attackingWays;
}

signed main(){
    int n;
    cin >> n;

    for(int k = 1;k <= n;k++){
        cout<<solve(k)<<endl;
    }

    return 0;
}