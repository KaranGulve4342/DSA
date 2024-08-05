// EVERY PROBLEM IS SOLVABLE

// CODEFORCES 1100 RATED
#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve() {
    int n;
    cin >> n;

    if (n == 0) return 0;  // Edge case: no elements

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int gcd1 = 0;
    int gcd2 = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            gcd1 = __gcd(gcd1, arr[i]);
        } else {
            gcd2 = __gcd(gcd2, arr[i]);
        }
    }

    bool flag = true;

    for (int i = 0; i < n; i++) {
        if(!(i&1)){
            if (arr[i] % gcd2 == 0) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        return gcd2;
    }

    flag = true;

    for (int i = 0; i < n; i++) {
        if(i&1){
            if (arr[i] % gcd1 == 0) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        return gcd1;
    }

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}
