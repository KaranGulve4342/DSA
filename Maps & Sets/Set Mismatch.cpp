// LEETCODE 645

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;

        for(int i = 0;i < n;i++){
            umap.insert({i+1, 0});
            umap[nums[i]]++;
        }
        int p, q;
        for(auto x : umap){
            if(x.second == 2){
                p = x.first;
            }
            if(x.second == 0){
                q = x.first;
            }
        }
        return {p, q};
    }
};