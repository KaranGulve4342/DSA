// LEETCODE 1358

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int count = 0;

        unordered_map<char, int> umap;

        while(j < n){

            umap[s[j]]++;

            while(umap['a'] >= 1 && umap['b'] >= 1 && umap['c'] >= 1){
                count += (n-j);
                umap[s[i]]--;
                i++;
            }
            
            j++;

        }

        return count;
    }
};