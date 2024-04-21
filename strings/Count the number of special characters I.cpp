// LEETCODE 3120

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lo;
        unordered_set<char> up;
        int count = 0;

        for (char ch : word) {
            if (islower(ch)) {
                lo.insert(ch);
            } else if (isupper(ch)) {
                up.insert(ch);
            }
        }

        for (char ch : lo) {
            if (up.find(toupper(ch)) != up.end()) {
                count++;
            }
        }

        return count;
    }
};
