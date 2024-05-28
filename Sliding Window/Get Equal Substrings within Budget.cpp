// LEETCODE 1208

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff(s.length(), 0);

        for(int i = 0;i < s.length();i++){
            int cost = abs(s[i] - t[i]);
            diff[i] = cost;
        }

        int maxLength = 0, sum = 0, start = 0;
        for (int end = 0; end < diff.size(); end++) {
            sum += diff[end];

            while (sum > maxCost) {
                sum -= diff[start];
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};