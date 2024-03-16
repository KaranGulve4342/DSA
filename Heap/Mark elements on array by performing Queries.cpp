// LEETCODE 3080

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        unordered_set<int> marked;
        vector<long long> ans;
        
        // Create a min-heap of pairs (value, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i)
            pq.push({nums[i], i});
        
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);  

        for (auto& query : queries) {
            int index = query[0];
            int k = query[1];
            if (marked.find(index) == marked.end()) {
                marked.insert(index);
                totalSum -= nums[index];
            }
            
            while (k > 0 && !pq.empty()) {
                auto [value, idx] = pq.top(); 
                pq.pop();
                if (marked.find(idx) == marked.end()) {
                    marked.insert(idx);
                    totalSum -= value;
                    k--;
                }
            }
            
            ans.push_back(totalSum);
        }
        
        return ans;
    }
};