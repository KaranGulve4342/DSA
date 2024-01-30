// LEETCODE 567

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> umap;

        if(s1.length() > s2.length()){
            return false;
        }

        for (char ch : s1) {
            umap[ch]++;
        }
        int k = s1.length();

        for (int i = 0; i <= s2.length() - k; i++) {
            unordered_map<char, int> tempMap = umap; 
            int j = i;
            while (j < i + k) {
                if (tempMap.find(s2[j]) != tempMap.end() && tempMap[s2[j]] > 0) {
                    tempMap[s2[j]]--;
                    j++;
                } else {
                    break; 
                }
            }

            if (j == i + k) {
                return true;
            }
        }

        return false;
    }
};