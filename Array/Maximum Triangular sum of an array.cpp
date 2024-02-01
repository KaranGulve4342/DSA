// LEETCOODE 2221

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() != 1){
            vector<int> curr;
            for(int i = 1;i < nums.size();i++){
                curr.push_back((nums[i] + nums[i-1])%10);
            }
            nums = curr;
        }
        return nums[0];
    }
};