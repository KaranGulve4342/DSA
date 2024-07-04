// CODEFORCES 1000 RATED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minRecolorings(const string& s, int n, int k) {
    int min_whites = k;  // At most, all k could be white
    int current_whites = 0;

    // Initial window
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'W') {
            ++current_whites;
        }
    }
    min_whites = current_whites;

    // Sliding window
    for (int i = k; i < n; ++i) {
        if (s[i] == 'W') {
            ++current_whites;
        }
        if (s[i - k] == 'W') {
            --current_whites;
        }
        min_whites = min(min_whites, current_whites);
    }

    return min_whites;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        cout << minRecolorings(s, n, k) << endl;
    }
    return 0;
}
