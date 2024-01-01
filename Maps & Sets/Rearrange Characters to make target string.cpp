// LEETCODE 2287

/*
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> sFreq;
        unordered_map<char, int> targetFreq;

        for(int i = 0;i < s.length();i++){
            sFreq[s[i]]++;
        }
        for(int i = 0;i < target.length();i++){
            targetFreq[target[i]]++;
        }
        int maxCopies = INT_MAX;
        for(auto ch : target){
            if(sFreq.find(ch) == sFreq.end()) return 0;
            maxCopies = min(maxCopies, sFreq[ch]/targetFreq[ch]);
        }
        return maxCopies;
    }
};
*/