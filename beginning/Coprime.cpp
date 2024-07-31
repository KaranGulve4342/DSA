// CODEFORCES 1100 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> idx(1001, -1);

    for(int i = 0; i < n; i++) {
        idx[a[i]] = i;
    }

    int ans = -1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = i; j <= 1000; j++) {
            if(idx[i] >= 0 && idx[j] >= 0) {
                if(__gcd(i, j) == 1) {
                    ans = max(ans, idx[i] + idx[j] + 2);
                }
            }
        }
    }

    return ans;
}

signed main() {
    int T;
    cin >> T;

    while(T--) {
        cout << solve() << endl;
    }
    return 0;
}
