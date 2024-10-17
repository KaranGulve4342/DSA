// LEETCODE 410

class Solution {
public:
    int find(vector<int>& nums, int sum){
        int c = 1;
        int currSum = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(currSum + nums[i] > sum){
                c++;
                currSum = nums[i];
            }
            else{
                currSum += nums[i];
            }
        }
        return c;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            int sumCount = find(nums, mid);

            if(sumCount <= k){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};