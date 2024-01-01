// LEETCODE 1282

/*
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        unordered_map<int, vector<int>> group;

        for(int i = 0;i < n;i++){
            int size = groupSizes[i];
            group[size].push_back(i);
        }
        vector<vector<int>> ans;

        for(auto pair:group){
            int size = pair.first;
            vector<int> group = pair.second;

            for(int i = 0;i < group.size();i+=size){
                vector<int> subgroup(group.begin() + i, group.begin() + i + size);
                ans.push_back(subgroup);
            }
        }
        return ans;
    }
};
*/