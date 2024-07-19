// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    // Flag to check if a solution is found
    bool found = false;
    int l = 0, r = 0;

    // Find the first position where a character is greater than the next character
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            l = i;
            r = i + 1;
            found = true;
            break;
        }
    }

    // If a solution is found, print "YES" and the indices
    if (found) {
        cout << "YES" << endl;
        cout << l + 1 << " " << r + 1 << endl;  // Convert 0-based indices to 1-based
    } else {
        // If no solution is found, print "NO"
        cout << "NO" << endl;
    }

    return 0;
}
