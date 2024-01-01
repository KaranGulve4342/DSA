// LEETCODE 1793

/*
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k;
        int right = k;
        int min_Value = nums[k];
        int max_Score = min_Value;

        while(left > 0 || right < nums.size() - 1){
            if(left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1])){
                right++;
            }
            else {
                left--;
            }

            min_Value = min(min_Value,min(nums[left], nums[right]));
            max_Score = max(max_Score, (min_Value * (right - left + 1)));
        }
        return max_Score;
    }
};
*/