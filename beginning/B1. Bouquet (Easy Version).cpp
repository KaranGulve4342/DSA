// CODEFORCES 1100 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int start = 0;
    int sum = 0;
    int ans = 0;

    for(int i = 0;i < n;i++){
        sum += arr[i];
        while(sum > m || (start < n && (arr[i] - arr[start]) > 1)){
            sum -= arr[start];
            start++;
        }
        ans = max(ans, sum);
    }
    return ans;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}