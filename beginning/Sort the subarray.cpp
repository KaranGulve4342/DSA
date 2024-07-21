// CODEFORCES 1100 RATED

#include <bits/stdc++.h>

#define int long long

using namespace std;


int solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a){
        cin >> i;
    }
    for (auto &i : b){
        cin >> i;
    }
    int l = 0, r = n - 1;

    while (a[l] == b[l]){
        l++;
    }
    while (a[r] == b[r]){
        r--;
    }
    while (l > 0 && b[l] >= b[l - 1]){
        l--;
    }
    while (r < n - 1 && b[r] <= b[r + 1]){
        r++;
    }

    cout << l + 1 << " " << r + 1 << endl;
    return 0;
}
signed main()
{
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
