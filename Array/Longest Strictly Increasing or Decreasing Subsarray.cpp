// LEETCODE 3105

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int sz = 1;
        int mxsz = 1;
        
        for(int i = 0; i < n - 1; i++) {
            while(i < n - 1 && nums[i] < nums[i + 1]) {
                sz++;
                i++;
            }
            mxsz = max(mxsz, sz);
            sz = 1;
        }
        
        sz = 1; 
        for(int i = 0; i < n - 1; i++) { 
            while(i < n - 1 && nums[i] > nums[i + 1]) { 
                sz++;
                i++;
            }
            mxsz = max(mxsz, sz);
            sz = 1;
        }
        
        return mxsz;
    }
};