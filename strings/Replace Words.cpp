// LEETCODE 648

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
// Return the sentence after the replacement.

// Example 1:
// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"

// Example 2:
// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"

// Example 3:
// Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
// Output: "a a a a a a a a bbb baba a"

// Example 4:
// Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"

// Example 5:
// Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
// Output: "it is ab that this solution is ac"

// Constraints:
// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case letters.
// 1 <= sentence.length <= 10^6
// sentence consists of only lower-case letters and spaces.
// The number of words in sentence is in the range [1, 1000]
// The length of each word in sentence is in the range [1, 1000]
// Each two consecutive words in sentence will be separated by exactly one space.
// sentence does not have leading or trailing spaces.

// Solution:
// The idea is to store all the roots in a set and then iterate over the sentence.
// If the current word is a root, then add it to the answer and move to the next word.
// If the current word is not a root, then keep adding the characters of the word to a temporary string.
// If the temporary string is a root, then add it to the answer and move to the next word.
// If the temporary string is not a root, then keep adding the characters of the word to the temporary string.
// If the temporary string is not empty, then add it to the answer.
// Finally, return the answer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        unordered_set<string> uset(dictionary.begin(), dictionary.end());
        string ans = "";
        string temp = "";

        for(int i = 0;i < sentence.size();){
            if(sentence[i] == ' '){
                ans += temp;
                ans += ' ';
                temp = "";
            }
            else{
                temp += sentence[i];

                if(uset.find(temp) != uset.end()){
                    while(i < sentence.size() && sentence[i] != ' '){
                        i++;
                    }

                    ans += temp;
                    temp = "";
                    continue;
                }
            }
            i++;
        }

        if(temp.length() != 0){
            ans += temp;
        }

        return ans;
    }
};