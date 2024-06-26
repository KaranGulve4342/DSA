// LEETCODE 3163

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string ans = "";

        int n = word.length();

        for(int i = 0;i < n;){
            char curr = word[i];
            int count = 0;

            while(i < n && word[i] == curr && count < 9){
                i++;
                count++;
            }

            ans += to_string(count) + curr;
        }
        return ans;
    }
};