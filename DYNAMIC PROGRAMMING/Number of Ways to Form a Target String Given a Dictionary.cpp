// LEETCODE 1639

class Solution {
public:
    long MOD = 1e9 + 7;
    long getWords(vector<string>& words, string &target, int i, int j, vector<vector<int>>& dp){
        if(j == target.size()){
            return 1;
        }
        if(i == words[0].size() || words[0].size() - i < target.size() - j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        long count = 0;

        for(int idx = 0;idx < words.size();idx++){
            if(words[idx][i] == target[j]){
                count += getWords(words, target, i+1, j+1, dp)%MOD;
            }
        }

        count += getWords(words, target, i+1, j, dp)%MOD;

        return dp[i][j] = count%MOD;
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> dp(words[0].size(), vector<int>(target.size(), -1));
        return getWords(words, target, 0, 0, dp);
    }
};