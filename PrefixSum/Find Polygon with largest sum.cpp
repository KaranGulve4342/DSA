// LEETCODE 2971

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        long long int ans = -1;
        long long int prevSum = 0;

        for(auto num : nums){
            if(num < prevSum){
                ans = num + prevSum;
            }
            prevSum += num;
        }
        return ans;
        
    }
};