// CODEFORCES 1100 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(){
    int n, c;
    cin >> n >> c;

    vector<int>arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        arr[i] += (i+1);
    }

    sort(arr.begin(), arr.end());

    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
        if(sum > c){
            return i;
        }
    }
    return n;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}