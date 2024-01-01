// LEETCODE 771

/*
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> umap;

        for(char st : stones){
            umap[st]++;
        }
        int count = 0;
        for(char jwl : jewels){
            if(umap.find(jwl) != umap.end()){
                count += umap[jwl];
            }
        }
        return count;
    }
};
*/