// LEETCODE 2442

class Solution {
public:
    int reverse(int n){
        int r = 0;
        while(n > 0){
            r *= 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> uset;
        for(int i = 0;i < nums.size();i++){
            uset.insert(nums[i]);
            uset.insert(reverse(nums[i]));
        }
        return uset.size();
    }
};