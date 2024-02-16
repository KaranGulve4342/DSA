// LEETCODE 1481

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> umap;
        for(auto num : arr){
            umap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto x : umap){
            pq.push({x.second, x.first});
        }

        while(k > 0 && !pq.empty()){
            auto [count, num] = pq.top();
            pq.pop();
            if(count <= k) {
                k -= count;
            } else {
                pq.push({count - k, num});
                k = 0;
            }
        }

        return pq.size();
    }
};