// LEETCODE 2958

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int n = nums.size();

        int mxlen = 0;
        int i = 0;
        for(int j = 0;j < n;j++){
            umap[nums[j]]++;
            while(umap[nums[j]] > k){
                umap[nums[i]]--;
                i++;
            }
            mxlen = max(mxlen, j-i+1);
        }
        return mxlen;
    }
};