// LEETCODE 973

/*
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(auto it : points){
            int dist = it[0]*it[0] + it[1]*it[1];
            pq.push({dist,{it[0], it[1]}});
        }
        vector<vector<int>> ans;
        while(k--){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            ans.push_back({row, col});
        }
        return ans;
    }
};
*/