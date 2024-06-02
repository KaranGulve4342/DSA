// LEETCODE 3168

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int curr = 0;
        int maxi = 0;
        
        for (auto ch : s) {
            if (ch == 'E') {
                curr++;
                maxi = max(maxi, curr);
            } else if (ch == 'L') {
                curr--;
            }
        }
        
        return maxi;
    }
};