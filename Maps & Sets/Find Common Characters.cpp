// LEETCODE 1002

// Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).
// For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
// You may return the answer in any order.

// Example 1:
// Input: ["bella","label","roller"]
// Output: ["e","l","l"]

// Example 2:
// Input: ["cool","lock","cook"]
// Output: ["c","o"]

// Note:
// 1 <= A.length <= 100
// 1 <= A[i].length <= 100

// Time Complexity: O(N * M), where N is the number of strings in the input list and M is the maximum length of a string in the list.
// Space Complexity: O(1) since the output list is not considered as extra space.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize the common frequency array with large values
        vector<int> commonFreq(26, INT_MAX);
        
        // Iterate over each word in the list
        for (const string& word : words) {
            vector<int> wordFreq(26, 0);
            // Count frequencies of each character in the current word
            for (char ch : word) {
                wordFreq[ch - 'a']++;
            }
            // Update the common frequency array to the minimum frequencies
            for (int i = 0; i < 26; ++i) {
                commonFreq[i] = min(commonFreq[i], wordFreq[i]);
            }
        }
        
        // Collect the characters that appear in all words
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            while (commonFreq[i] > 0) {
                result.push_back(string(1, 'a' + i));
                commonFreq[i]--;
            }
        }
        
        return result;
    }
};