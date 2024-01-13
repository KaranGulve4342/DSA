// LEETCODE 1347

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> umap;
        
        for(int i = 0;i < s.length();i++){
            umap[s[i]]++;
            umap[t[i]]--;
        }
        int ans = 0;
        for(auto x : umap){
            if(x.second > 0) ans += x.second;
        }
        return ans;

    }
};