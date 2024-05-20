// LEETCODE 2305

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& cookies, int idx, vector<int>& temp, int k) {
        if (idx == cookies.size()) {
            return *max_element(temp.begin(), temp.end());
        }
        int mini = INT_MAX;
        for (int j = 0; j < k; j++) {
            temp[j] += cookies[idx];
            mini = min(mini, solve(cookies, idx + 1, temp, k));
            temp[j] -= cookies[idx];
        }
        return mini;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k, 0);  // Initialize temp with k elements, each set to 0
        return solve(cookies, 0, temp, k);
    }
};
