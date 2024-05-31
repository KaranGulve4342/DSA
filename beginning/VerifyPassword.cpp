#include <bits/stdc++.h>
using namespace std;

bool barobar(vector<char>::iterator begin, vector<char>::iterator end) {
    for (auto it = begin; it != end - 1; ++it) {
        if (*it > *(it + 1)) {
            return false;
        }
    }
    return true;
}

bool karan() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<char> digits;
    vector<char> letters;
    bool flag = false;

    for (auto ch : str) {
        if (isdigit(ch)) {
            digits.push_back(ch);
        } else {
            letters.push_back(ch);
        }
    }

    if (!is_sorted(digits.begin(), digits.end())) {
        return false;
    }

    if (!is_sorted(letters.begin(), letters.end())) {
        return false;
    }

    for (auto ch : str) {
        if (isalpha(ch)) {
            flag = true;
        } else if (flag && isdigit(ch)) {
            return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    // vector<string> results;
    while (T--) {
        if (karan()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
