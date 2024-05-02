// LEETCODE 2441

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> uset;
        for(int i = 0;i < nums.size();i++){
            uset.insert(nums[i]);
        }

        for(auto x : uset){
            if(uset.find(-x) != uset.end()){
                if(abs(x) > ans){
                    ans = abs(x);
                }
            }
        }
        return ans;
    }
};