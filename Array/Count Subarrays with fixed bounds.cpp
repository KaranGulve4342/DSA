// LEETCODE 2444

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        bool mnfound = false;
        bool mxfound=  false;

        int start = 0;
        int mnStart = 0;
        int mxStart = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] < minK || nums[i] > maxK){
                mnfound = false;
                mxfound = false;
                start = i+1;
            }
            if(nums[i] == minK){
                mnfound=  true;
                mnStart = i;
            }
            if(nums[i] == maxK){
                mxfound = true;
                mxStart = i;
            }
            if(mnfound && mxfound){
                ans += (min(mnStart, mxStart) - start+1);
            }
        }
        return ans;
    }
};