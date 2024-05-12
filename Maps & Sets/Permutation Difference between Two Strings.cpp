// LEETCODE 3146

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> umap;

        for(int i = 0;i < s.length();i++){
            umap[s[i]] = i;
        }

        int ans = 0;
        for(int i = 0;i < t.length();i++){
            ans += abs(umap[t[i]] - i);
        }

        return ans;
    }
};