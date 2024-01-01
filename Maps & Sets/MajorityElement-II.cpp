// LEETCODE 229
/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i = 0;i < nums.size();i++){
            umap[nums[i]]++;
        }
        vector<int> ans;
        int mx = nums.size()/3;
        for(auto x : umap){
            if(mx < x.second){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
*/