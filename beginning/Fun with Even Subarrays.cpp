// EVERY PROBLEM IS SOLVABLE

// CODEFORCES 1100 - Fun with Even Subarrays

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    int x = arr[n-1];
    int i = n-1;
    int count = 0;
    int steps = 0;

    while(i >= 0){
        while(arr[i] == x && i >= 0){
            count++;
            i--;
        }

        if(i < 0){
            break;
        }

        steps++;
        i -= count;
        count *= 2;
    }

    return steps;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}