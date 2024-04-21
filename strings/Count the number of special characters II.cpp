// LEETCODE 3121

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lo;
        unordered_map<char, int> up;
        
        for (int i = 0; i < word.length(); ++i) {
            char c = tolower(word[i]);
            if (islower(word[i])) {
                lo[c] = i;
            } else {
                if (up.find(c) == up.end()) {
                    up[c] = i;
                }
            }
        }
        
        int count = 0;
        for (auto entry : lo) {
            char key = entry.first;
            int value = entry.second;
            if (up.find(key) != up.end() && value < up[key]) {
                count++;
            }
        }
        
        return count;
    }
};