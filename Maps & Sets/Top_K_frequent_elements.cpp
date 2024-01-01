// LEETCODE 347

/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }

        vector<pair<int, int>> sortedUmap(umap.begin(),umap.end());
        sort(sortedUmap.begin(), sortedUmap.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(sortedUmap[i].first);
        }
        return result;
    }
};


*/