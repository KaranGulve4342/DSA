// LEETCODE 47

class Solution {
public:
    void permutations(int idx, vector<int>&nums, set<vector<int> >&st){
        if(idx == nums.size()){
            st.insert(nums);
            return;
        }

        for(int i = idx;i < nums.size();i++){
            swap(nums[idx], nums[i]);
            permutations(idx + 1, nums, st);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >ans;
        set<vector<int> > st;
        sort(nums.begin(), nums.end());
        permutations(0, nums, st);

        for(auto it : st){
            ans.push_back(it);
        }

        return ans;
    }
};