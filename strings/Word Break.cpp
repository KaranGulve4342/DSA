// LEETCODE 139

class Solution {
public:
    int solve(int index, string s, unordered_set<string>&uset, vector<int>&dp){
        if(index == s.length()){
            return 1;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        string temp = "";
        for(int i = index;i < s.length();i++){
            temp += s[i];
            if(uset.find(temp) != uset.end()){
                if(solve(i+1, s, uset, dp)) return dp[i] = 1;
            }
        }
        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;
        int n = s.length();

        for(auto word : wordDict){
            uset.insert(word);
        }
        vector<int> dp(n+1, -1);
        return solve(0, s, uset, dp);

    }
};