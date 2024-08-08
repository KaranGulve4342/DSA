// LEETCODE 93

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    bool check(string &S) {
        int n = S.length();

        if (n <= 0 || n > 3) {
            return false;
        }

        if (n > 1 && S[0] == '0') {
            return false;
        }

        int num = stoi(S);

        if (num < 0 || num > 255) {
            return false;
        }

        return true;
    }

    string generateIP(string &s, int &n, int &i, int &j, int &k) {
        string s1 = s.substr(0, i + 1);
        string s2 = s.substr(i + 1, j - i);
        string s3 = s.substr(j + 1, k - j);
        string s4 = s.substr(k + 1, n - k - 1);

        if (check(s1) && check(s2) && check(s3) && check(s4)) {
            return s1 + "." + s2 + "." + s3 + "." + s4;
        }
        return "";
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();

        if (n < 4 || n > 12) { 
            return {};
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    string str = generateIP(s, n, i, j, k);

                    if (str.length() > 0) {
                        ans.push_back(str);
                    }
                }
            }
        }

        return ans;
    }
};