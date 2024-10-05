// LEETCODE 953

class Solution {
public:
    unordered_map<char, int> umap;
    bool check(string word1, string word2){
        int len = min(word1.length(), word2.length());

        for(int i = 0;i < len;i++){
            if(umap[word1[i]] > umap[word2[i]]){
                return false;
            }
            else if(umap[word1[i]] < umap[word2[i]]){
                return true;
            }
        }

        if((word1.length() > word2.length() && word1.find(word2) != string::npos)){
            return false;
        }

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int len = order.length();

        for(int i = 0;i < len;i++){
            umap[order[i]] = i;
        }
        int n = words.size();
        for(int i = 0;i < n-1;i++){
            if(!(check(words[i], words[i+1]))){
                return false;
            }
        }

        return true;
    }
};