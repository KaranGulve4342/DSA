// LEETCODE 3137

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();

        unordered_map<string, int> count;

        for(int i = 0;i < n;i += k){
            string s = word.substr(i, k);
            count[s]++;
        }

        int mx = 0;
        for(auto pair : count){
            mx = max(mx, pair.second);
        }

        return ((n/k) - mx);
    }
};