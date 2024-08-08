// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(vector<int> &v, int idx, int sum1, int sum2, int n){
    if(idx == n){
        return abs(sum1 - sum2);
    }

    int choose = solve(v, idx + 1, sum1 + v[idx], sum2, n);
    int notChoose = solve(v, idx + 1, sum1, sum2 + v[idx], n);

    return min(choose, notChoose);
}

signed main(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0;i < n;i++){
        cin >> v[i];
    }

    cout<<solve(v, 0, 0, 0, n)<<endl;

    return 0;
}