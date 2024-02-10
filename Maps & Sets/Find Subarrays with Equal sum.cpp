// LEETCODE 2395

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, int> umap;

        for(int i = 1;i < nums.size();i++){
            int sum = nums[i] + nums[i-1];

            if(umap.find(sum) != umap.end()){
                return true;
            }
            umap[sum]++;
        }
        return false;
    }
};