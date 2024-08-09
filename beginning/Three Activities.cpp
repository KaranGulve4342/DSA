// CODEFORCES 1200 RATED

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<pair<int, int>> v1, v2, v3;

    for(int i = 0; i < n; i++) {
        v1.push_back({a[i], i});
        v2.push_back({b[i], i});
        v3.push_back({c[i], i});
    }

    sort(v1.begin(), v1.end(), greater<>());
    sort(v2.begin(), v2.end(), greater<>());
    sort(v3.begin(), v3.end(), greater<>());

    int ans = LLONG_MIN; // Initialize to a very small value

    int size = min(3LL, n); // Ensure we don't go out of bounds

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                if(v1[i].second != v2[j].second && v1[i].second != v3[k].second && v2[j].second != v3[k].second) {
                    ans = max(ans, v1[i].first + v2[j].first + v3[k].first);
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
