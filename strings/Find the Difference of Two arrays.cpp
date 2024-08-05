// LEETCODE 2215

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> v = {};
        unordered_set<int> uset;

        for(auto num : nums2){
            uset.insert(num);
        }

        for(auto num : nums1){
            if(uset.find(num) == uset.end()){
                v.push_back(num);
                uset.insert(num);
            }
        }

        ans.push_back(v);
        v.clear();
        uset.clear();

        for(auto num : nums1){
            uset.insert(num);
        }

        for(auto num : nums2){
            if(uset.find(num) == uset.end()){
                v.push_back(num);
                uset.insert(num);
            }
        }
        ans.push_back(v);

        return ans;
    }
};