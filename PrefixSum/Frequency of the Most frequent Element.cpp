// LEETCODE 1838

/*
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        long long sum = 0;
        int maxFreq = 1;

        for(int j = 0;j < nums.size();j++){
            sum += nums[j];

            if((long long)nums[j] * (j-i+1) > sum+k){
                sum -= nums[i];
                i++;
            }
            maxFreq = max(maxFreq, j-i+1);
        }
        return maxFreq;
    }
};
*/