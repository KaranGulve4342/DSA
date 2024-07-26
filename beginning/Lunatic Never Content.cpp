// CODEFORCES 1100 RATED

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
    int ans = abs(arr[n-1] - arr[0]);

    for(int i = 0;i < n;i++){
        int j = n-i;
        ans = __gcd(ans, abs(arr[j-1] - arr[i]));
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
