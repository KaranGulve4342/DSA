// LEETCODE 1638

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<int>> dp1(m+1, vector<int>(n+1, 0));
        vector<vector<int>> dp2(m+1, vector<int>(n+1, 0));

        int ans = 0;

        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == t[j-1]){
                    dp1[i][j] =  1 + dp1[i-1][j-1];
                    dp2[i][j] = dp2[i-1][j-1];
                }
                else{
                    dp2[i][j] = 1 + dp1[i-1][j-1];
                }

                ans += dp2[i][j];
            }
        }

        return ans;
    }
};