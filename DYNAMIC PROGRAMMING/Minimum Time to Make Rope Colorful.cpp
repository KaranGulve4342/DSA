// LEETCODE 1578

class Solution {
public:
    int calculateMinCost(int i, string& colors, vector<int>& neededTime, vector<int> &dp, char prevColor, int prevTime ){
        if(i < 0){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        if(colors[i] == prevColor){
            return dp[i] = calculateMinCost(i-1, colors, neededTime, dp, colors[i], max(neededTime[i], prevTime)) + min(neededTime[i], prevTime);
        }
        else{
            return dp[i] = calculateMinCost(i-1, colors, neededTime, dp, colors[i], neededTime[i]);
        }


    }

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();

        vector<int> dp(n, -1);

        return calculateMinCost(n-1, colors, neededTime, dp, 'A', neededTime[n-1]);
    }
};