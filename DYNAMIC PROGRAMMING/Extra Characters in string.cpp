// LEETCODE 2707

class Solution {
public:
    int solve(int idx, string s, unordered_set<string>& st, vector<int>& dp){
        if(idx == s.length()){
            return 0;
        }

        if(dp[idx] != INT_MAX){
            return dp[idx];
        }

        int ans = solve(idx + 1, s, st, dp) + 1;

        for(int end = idx; end < s.length(); end++){
            auto curr = s.substr(idx, end - idx + 1);

            if(st.find(curr) != st.end()){
                ans = min(ans, solve(end + 1, s, st, dp));
            }
        }

        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();

        unordered_set<string> st(dictionary.begin(), dictionary.end());

        vector<int> dp(n + 1, INT_MAX);  

        return solve(0, s, st, dp);
    }
};
