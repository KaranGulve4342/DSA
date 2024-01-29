// LEETCODE 611

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        sort(nums.begin(), nums.end());

        for(int i = n-1;i >= 2;i--){
            int j = 0;
            int k = i-1;

            while(j < k){
                if(nums[j] + nums[k] > nums[i]){
                    count += k - j;
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return count;
    }
};