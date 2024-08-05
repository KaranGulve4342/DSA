// LEETCODE 884

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> umap;
        string s = "";
        for(int i = 0;i < s1.length();i++){
            if(s1[i] == ' '){
                umap[s]++;
                s = "";
            }
            else{
                s += s1[i];
            }
        }
        umap[s]++;
        s = "";

        for(int i = 0;i < s2.length();i++){
            if(s2[i] == ' '){
                umap[s]++;
                s = "";
            }
            else{
                s += s2[i];
            }
        }
        umap[s]++;
        s = "";
        vector<string> ans;
        for(auto x : umap){
            if(x.second == 1){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};