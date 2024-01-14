// LEETCODE 1657

class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length() != str2.length()) return false;
        unordered_map<char, int> umap1;
        unordered_map<char, int> umap2;

        for(int i = 0;i < str1.length();i++){
            umap1[str1[i]]++;
            umap2[str2[i]]++;
        }
        for(auto x : umap1){
            char ch = x.first;
            if(umap2.find(ch) == umap2.end()) return false;
        }

        unordered_map<int, int> h1;
        unordered_map<int, int> h2;

        for(auto x : umap1){
            int freq = x.second;
            h1[freq]++;
        }
        for(auto x : umap2){
            int freq = x.second;
            h2[freq]++;
        }
        // comparing h1 and h2
        for(auto x : h1){
            int key = x.first;
            if(h2.find(key) == h2.end()) return false;
            if(h2[key] != h1[key]) return false;
        }
        return true;
    }
};