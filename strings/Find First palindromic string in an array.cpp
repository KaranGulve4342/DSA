// LEETCODE 2108

class Solution {
public:
     bool isPalindrome(string str){
        string rev = str; // Make a copy of str
        reverse(rev.begin(), rev.end()); // Reverse the copy
        return (str == rev);
    }
    string firstPalindrome(vector<string>& words) {
        for(auto word : words){
            if(isPalindrome(word)){
                return word;
            }
        }

        return "";
    }
};