// LEETCODE 409

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> umap;

        for(auto ch : s){
            umap[ch]++;
        }

        int len = 0;
        bool flag = false;
        for(auto x : umap){
            if(x.second % 2 == 1){
                len += (x.second - 1);
                flag = true;
            }
            else if(x.second % 2 == 0){
                len += x.second;
            }
        }

        if(flag) return len+1;
        return len;
    }
};