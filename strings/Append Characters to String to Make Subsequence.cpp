// LEETCODE 2486

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;

        int m = s.length();
        int n = t.length();

        while(i < m && j < n){
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }

        return n - j;
    }
};