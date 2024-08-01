
// EVERY PROBLEM IS SOLVABLE
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    int i = -1;
    while(i < n) {
        while(i >= 0 && i < n && s[i] == 'W') {
            i++;
            k--;
            if(k < 0) {
                cout << "NO" << endl;
                return;
            }
        }
        if(s[i] == 'C') {
            cout << "NO" << endl;
            return;
        }
        bool flag = false;
        for(int j = m; j >= 1; j--) {
            if(i + j >= n) {
                cout << "YES" << endl;
                return;
            }
            if(s[i + j] == 'L') {
                i += j;
                flag = true;
                break;
            }
        }
        if(flag) continue;
        for(int j = m; j >= 1; j--) {
            if(s[i + j] == 'W') {
                i += j;
                flag = true;
                break;
            }
        }
        if(flag) continue;
        cout << "NO" << endl;
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
