// LEETCODE 3136

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        int vowel = 0;
        int consonant = 0;
        bool flag = false;

        for(auto c : word){
            if(isalpha(c)){
                char lowercaseChar = tolower(c);
                if(lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' || lowercaseChar == 'u') {
                    vowel++;
                }
                else{
                    consonant++;
                }
            }
            else{
                if(!isalnum(c)){
                    return false;
                }
            }
        }

        return (word.length() >= 3 && vowel > 0 && consonant > 0);
    }
};