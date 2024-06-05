// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        result ^= arr[i];
    }

    int check = 0;
    for (int i = 0; i < n; ++i){
        check ^= (arr[i] ^ result);
    }

    if (!check) return result;
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }

    return 0;
}
