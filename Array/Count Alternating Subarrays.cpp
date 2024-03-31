// LEETCODE 3101

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int count = 0;
        int start = 0;
        for(int i = 0;i < nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]){
                start = i;
            }
            count += (i - start + 1);
        }
        return count;
    }
};