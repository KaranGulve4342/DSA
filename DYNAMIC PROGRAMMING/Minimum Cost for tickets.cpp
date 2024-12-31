class Solution {
public:
    unordered_set<int> st;
    int solve(vector<int>& days, vector<int>&costs, vector<int>& dp, int currDay){
        if(currDay > days[days.size() - 1]){
            return 0;
        }

        if(st.find(currDay) == st.end()){
            return solve(days, costs, dp, currDay + 1);
        }

        if(dp[currDay] != -1){
            return dp[currDay];
        }

        int oneDay = costs[0] + solve(days, costs, dp, currDay + 1);
        int sevenDay = costs[1] + solve(days, costs, dp, currDay + 7);
        int thirtyDay = costs[2] + solve(days, costs, dp, currDay + 30);

        return dp[currDay] = min({oneDay, sevenDay, thirtyDay});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);

        for(auto day : days){
            st.insert(day);
        }

        return solve(days, costs, dp, 1);

    }
};