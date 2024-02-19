// LEETCODE 1329

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> umap;
        vector<vector<int> >ans(m, vector<int> (n, 0));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                umap[i-j].push_back(mat[i][j]);
            }
        }

        for(auto x : umap){
            vector<int> temp = x.second;
            sort(temp.begin(), temp.end(), greater<int>());
            umap[x.first] = temp;
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans[i][j] = umap[i-j].back();
                umap[i-j].pop_back();
            }
        }

        return ans;
    }
};