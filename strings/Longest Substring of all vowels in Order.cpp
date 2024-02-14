// LEETCODE 1839

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        char prev = 'a' - 1; // Set prev to a character smaller than 'a'
        int maxLength = 0;
        
        for(int i = 0; i < n;) {
            unordered_set<char> st;

            int j = i;
            while(j < n && word[j] >= prev) {
                prev = word[j];
                st.insert(word[j]);
                j++;
            }

            if(st.size() == 5) {
                maxLength = max(maxLength, j - i);
            }
            i = j;
            prev = 'a' - 1;
        }
        return maxLength;
    }
};
