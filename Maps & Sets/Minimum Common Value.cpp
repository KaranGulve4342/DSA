// LEETCODE 2540

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for(int i = 0;i < nums1.size();i++){
            umap[nums1[i]]++;
        }
        for(int i = 0;i < nums2.size();i++){
            if(umap.find(nums2[i]) != umap.end()){
                return nums2[i];
            }
        }
        return -1;
    }
};