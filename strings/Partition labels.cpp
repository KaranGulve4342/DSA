// LEETCODE 763

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> umap;
        for(int i = 0;i < s.length();i++){
            umap[s[i]] = i;
        }
        int end = 0;
        int start = 0;

        vector<int> ans;
        for(int i = 0;i < s.length();i++){
            end = max(end, umap[s[i]]);
            if(i == end){
                ans.push_back(end - start + 1);
                start = i+1;
            }
        }

        return ans;
    }
};