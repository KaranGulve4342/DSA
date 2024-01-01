// LEETCODE 45

/*

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        if(nums.size() <= 1) return 0;
        int lastIndex = nums.size() - 1;
        int count = 0;
        int start = 0;
        for(int i = 0;i <= maxReach;i++){
            maxReach = max(maxReach, i+nums[i]);
            if(i == start){
                start = maxReach;
                count++;
            }
            if(start >= lastIndex) return count;
            
        }
        return count;
    }
};

*/