// LEETCODE 2924

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for(auto edge : edges){
            auto u = edge[0];
            auto v = edge[1];

            adjList[v].push_back(u);
        }

        int ans = -1;
        for(int i = 0;i < n;i++){
            if(adjList[i].size() == 0){
                if(ans != -1){
                    return -1;
                }
                ans = i;
            }
        }

        return ans;
    }
};