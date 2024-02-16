// LEETCODE 2294

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int mn = nums[0];
        for(int i = 0;i < nums.size();i++){
            if((nums[i] - mn) > k){
                count++;
                mn = nums[i];
            }
        }
        return count+1;
    }
};