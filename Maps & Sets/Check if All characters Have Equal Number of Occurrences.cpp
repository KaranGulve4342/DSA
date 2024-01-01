// LEETCODE 1941

/*
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> umap;

        for(auto str : s){
            umap[str]++;
        }
        int k = umap[0].second;
        for(auto x : umap){
            if(x.second != k){
                return false;
            }
        }
        return true;
    }
};
*/