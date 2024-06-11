// CODEFORCES 900 RATED

#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 2;
    int maxi = 0;

    for (int i = 2; i <= n; i++) {
        int k = n / i;

        int total = k * (k + 1)/2;

        int sum = i * total;

        if (sum > maxi) {
            maxi = sum;
            ans = i;
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }
    
    return 0;
}
