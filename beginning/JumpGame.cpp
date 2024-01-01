// LEETCODE 55

/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int lastIndex = nums.size() - 1;

        for(int i=  0;i <= maxReach;i++){
            maxReach = max(maxReach, i + nums[i]);

            if(maxReach >= lastIndex) return true;
            if(maxReach <= i) return false;
        }
        return false;
    }
}
*/