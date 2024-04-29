// LEETCODE 2997

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto num : nums){
            k = k ^ num;
        }
        return __builtin_popcount(k);
    }
};