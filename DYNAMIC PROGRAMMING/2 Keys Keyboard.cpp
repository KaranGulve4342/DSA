// LEETCODE 650

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int solve(int currLen, int pasteLen, vector<vector<int>>& dp){
        if(currLen == n){
            return 0;
        }

        if(currLen > n){
            return 1000;
        }

        if(dp[currLen][pasteLen] != -1){
            return dp[currLen][pasteLen];
        }

        // copy all + paste
        int option1 = 2 + solve(currLen*2, currLen, dp);

        // paste
        int option2 = 1 + solve(currLen + pasteLen, pasteLen, dp);

        return dp[currLen][pasteLen] = min(option1, option2);
    }
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        this->n = n;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return 1 + solve(1, 1, dp);
    }
};