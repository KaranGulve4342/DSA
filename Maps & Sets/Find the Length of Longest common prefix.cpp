// LEETCODE 3043

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> umap1, umap2;

        for(int i = 0;i < arr1.size();i++){
            string str = to_string(arr1[i]);

            for(int j = 0;j < str.length();j++){
                umap1[str.substr(0, j+1)]++;
            }
        }

        for(int i = 0;i < arr2.size();i++){
            string str = to_string(arr2[i]);

            for(int j = 0;j < str.length();j++){
                umap2[str.substr(0, j+1)]++;
            }
        }

        int ans = 0;
        for(auto x : umap1){
            if(umap2[x.first] >= 1){
                ans = max(ans, (int)((x.first).size()));
            }
        }
        return ans;
    }
};