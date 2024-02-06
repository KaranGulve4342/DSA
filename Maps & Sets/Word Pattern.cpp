// LEETCODE 290

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.length();
        vector<string> v;
        
        int i = 0;
        while(i < n){
            string str = "";
            while(i < n && s[i] != ' '){
                str += s[i];
                i++;
            }
            v.push_back(str);
            i++;
        }
        if(v.size() != pattern.length()){
            return false;
        }

        unordered_map<char, int> umap1;
        unordered_map<string, int> umap2;

        for(int i = 0;i < pattern.length();i++){
            if(umap2[v[i]] != umap1[pattern[i]]){
                return false;
            }
            umap2[v[i]] = i + 1;
            umap1[pattern[i]] = i + 1;
        }
        return true;
    }
};