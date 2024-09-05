// LEETCODE 2028

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;

        for(auto roll : rolls){
            sum += roll;
        }

        int total = mean*(m+n);
        int diff = total - sum;

        if(diff > 6*n || diff < n){
            return {};
        }

        int distributingMean = diff/n;
        int mod = diff%n;

        vector<int> ans(n, distributingMean);

        for(int i = 0;i < mod;i++){
            ans[i]++;
        }

        return ans;

    }
};