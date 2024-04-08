// LEETCODE 2527

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xorResult = 0;
        for(int i = 0;i < nums.size();i++){
            xorResult ^= nums[i];
        }
        return xorResult;
    }
};