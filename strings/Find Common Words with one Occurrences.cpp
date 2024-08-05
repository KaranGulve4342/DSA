// LEETCODE 2085

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> count1;
        unordered_map<string, int> count2;

        for (auto word : words1) {
            count1[word]++;
        }

        for (auto word : words2) {
            count2[word]++;
        }

        int count = 0;

        for (auto word : count1) {
            if (word.second == 1 && count2[word.first] == 1) {
                count++;
            }
        }

        return count;
    }
};