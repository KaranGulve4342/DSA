// LEETCODE 1684

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // unordered_set<char> uset;
        // for(auto ch : allowed){
        //     uset.insert(ch);
        // }

        // int count = 0;
        // for(auto word : words){
        //     bool flag = true;
        //     for(int i = 0;i < word.length();i++){
        //         if(uset.find(word[i]) == uset.end()){
        //             flag = false;
        //         }
        //     }
        //     if(flag) count++;
        // }
        // return count;

        int all = 0;
        for(auto ch : allowed){
            all |= 1 << (ch - 'a'); // setting that particular bit
        }

        int count = 0;
        for(auto word : words){
            bool flag = true;
            for(auto ch : word){
                if(all & (1 << (ch - 'a'))){ // check whether the bit is set or not
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};