// LEETCODE 1598

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;

        for(auto log : logs){
            if(log == "../"){
                ans--;
            }
            else if(log != "./"){
                ans++;
            }
            ans = max(0, ans);
        }

        return ans;
    }
};