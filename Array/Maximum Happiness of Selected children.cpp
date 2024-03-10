// LEETCODE 3075

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sorting in decreasing order
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long ans = 0;
        
        for (int i = 0; i < k; i++) {
            ans += max(0, happiness[i]-i);
        }
        
        return ans;
    }
};