// LEETCODE 678

// RECURSION + MEMOISATION
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int index, int count, string s, vector<vector<int> >&dp){
        if(index == s.length()){
            return (count == 0);
        }
        if(dp[index][count] != -1){
            return dp[index][count];
        }
        bool ans = false;
        if(s[index] == '*'){
            ans |= solve(index+1, count + 1, s, dp);
            if(count) ans |= solve(index+1, count-1, s, dp);
            ans |= solve(index+1, count, s, dp);
        }
        else{
            if(s[index] == '('){
                ans = solve(index + 1, count + 1, s, dp);
            }
            else{
                if(count) ans = solve(index+1, count - 1, s, dp);
            }
        }
        return dp[index][count]=ans;

    }
    bool checkValidString(string s) {
        int len = s.length();
        vector<vector<int> >dp(len+1, vector<int>(len+1, -1));
        return solve(0, 0, s, dp);
    }
};