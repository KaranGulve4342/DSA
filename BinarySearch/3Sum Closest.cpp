// LEETCODE 16

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int closestSum = INT_MAX;
        int minDiff = INT_MAX;

        for(int i = 0;i < n-2;i++){
            int low = i+1;
            int high = n-1;

            while(low < high){
                int currSum = nums[i] + nums[low] + nums[high];
                int currDiff = abs(currSum - target);

                if(currDiff < minDiff){
                    minDiff = currDiff;
                    closestSum = currSum;
                }

                if(currSum < target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }

        return closestSum;
    }
};