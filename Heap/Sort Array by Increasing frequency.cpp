// LEETCODE 1636

class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> umap;

        for(int num : nums){
            umap[num]++;
        }

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for(auto x : umap){
            pq.push({-x.second, x.first});
        }

        vector<int> ans;
        while(pq.size() > 0){
            int freq = pq.top().first;
            int num = pq.top().second;
            while(freq++){
                ans.push_back(num);
            }
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
