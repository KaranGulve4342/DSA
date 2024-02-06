// LEETCODE 383

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;

        for(auto ch : magazine){
            umap[ch]++;
        }

        for(int i = 0; i < ransomNote.length(); i++){
            if(umap.find(ransomNote[i]) != umap.end() && umap[ransomNote[i]] > 0){
                umap[ransomNote[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};