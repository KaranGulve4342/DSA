#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    // Frequency array for characters 'a' to 'z'
    vector<int> freq(26, 0);
    for(char c : s) {
        freq[c - 'a']++;
    }

    // Count of characters with odd frequencies
    int odd_count = 0;
    for(int count : freq) {
        if(count % 2 != 0) {
            odd_count++;
        }
    }

    // To form a palindrome, we need at most one character with an odd frequency
    // After removing k characters, if the remaining odd_count is <= 1, then it is possible
    int remaining_length = n - k;
    if (remaining_length % 2 == 0) {
        // If remaining length is even, we cannot have any odd frequency characters
        if (odd_count <= k) {
            return "YES";
        } else {
            return "NO";
        }
    } else {
        // If remaining length is odd, we can have one odd frequency character
        if (odd_count <= k + 1) {
            return "YES";
        } else {
            return "NO";
        }
    }
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        cout << solve() << endl;
    }

    return 0;
}
