// LEETCODE 3138

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.length();

        unordered_map<char, int> unique;

        for(char c : s){
            unique[c]++;
        }

        for(int t = 1;t <= n;t++){
            if(n % t == 0){
                bool flag = true;

                for(auto &[ch, freq] : unique){
                    if(freq % (n / t) != 0){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    return t;
                }
            }
        }
        return n;
    }
};