// LEETCODE 3144


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int idx, string s){
        if(idx < 0){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int freq[26] = {0};
        int minSubstrings = 5010;

        for(int j = idx;j >= 0;j--){
            freq[s[j] - 'a']++;
            int maxFreq = -1;
            int minFreq = 5010;

            for(int k = 0;k < 26;k++){
                if(freq[k] != 0){
                    minFreq = min(minFreq, freq[k]);
                    maxFreq = max(maxFreq, freq[k]);
                }
            }

            if(minFreq == maxFreq){
                minSubstrings = min(minSubstrings, 1 + solve(j-1, s));
            }
        }
        dp[idx] = minSubstrings;
        return minSubstrings;
    }
    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(5010, -1);
        return solve(n-1, s);
    }
};