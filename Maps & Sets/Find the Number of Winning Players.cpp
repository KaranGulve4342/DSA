// LEETCODE 3238

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int ans = 0;

        vector<unordered_map<int, int>> umap(n);

        for(auto p : pick){
            auto u = p[0];
            auto v = p[1];

            umap[u][v]++;
        }

        for(int i = 0;i < n;i++){
            for(auto x : umap[i]){
                if(x.second > i){
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};