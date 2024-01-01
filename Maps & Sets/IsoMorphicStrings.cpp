// LEETCODE 205

/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, char> umap1;
        unordered_map<char, char> umap2;

        for(int i = 0;i < s.length();i++){
            if(umap1[s[i]] != umap2[t[i]]){
                return false;
            }
            umap1[s[i]] = i + 1;
            umap2[t[i]] = i + 1;
        }
        return true;
    }
};
*/