// LEETCODE 72

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int  dp[505][505];
    int f(string &s1, string &s2, int i, int j){
        if(i == s1.size()) return s2.size() - j;
        if(j == s2.size()) return s1.size() - i;
        if(dp[i][j] != -1) return dp[i][j] = f(s1, s2, i+1, j+1);
        return dp[i][j] = min({1 + f(s1, s2, i+1, j+1), 1 + f(s1, s2, i+1, j), 1 + f(s1, s2, i, j+1)});
    }

    int minDistance(string word1, string word2){
        memset(dp, -1, sizeof dp);
        return f(word1, word2, 0, 0);
    }
}

int main()
{
    
    
    return 0;
}
/*
class Solution {
public:
    int minDistance(string s1, string s2){
        memset(dp, 0, sizeof dp);
        // base case
        for(int j = 0;j < s2.size();j++){
            int i=  s1.size();
            dp[i][j] = s2.size() - j;
        }
        for(int i=  0;i < s1.size();i++){
            int j = s2.size();
            dp[i][j] = s1.size() - i;
        }
        for(int i = s1.size() - 1;i >= 0;i--){
            for(int j = s2.size() - 1;j >= 0;j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = f(s1, s2, i+1, j+1);
                }
                else{
                    dp[i][j] = min({1+dp[i+1][j+1], 1+dp[i+1][j], 1+dp[i][j+1]});
                }
            }
        }
        return dp[0][0];
    }
}
*/

// RECURSION
/*
int solve(string& a, string& b, int i, int j){
    // base case
    if(i == a.length()){
        return b.length()-j;
    }
    if(j == b.length()){
        return a.length()-i;
    }

    int ans = 0;
    if(a[i] == b[j]){
        return solve(a, b, i+1, j+1);
    }
    else{
        // insert
        int insertAns = 1 + solve(a, b, i, j+1);

        // delete
        int deleteAns = 1 + solve(a, b, i+1, j);

        // replace
        int replaceAns = 1 + solve(a, b, i+1, j+1);

    }
    return min(insertAns, min(deleteAns, replaceAns));
}
int minDistance(string word1, string word2){
    return solve(word1, word2);
}
*/

// MEMOISATION
/*
int solve(string& a, string &b, int i, int j, vector<vector<int> >& dp){
    if(i == a.length()){
        return b.length() - j;
    }

    if(j == b.length()){
        return a.length() - i;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(a[i] == b[j]){
        return solve(a, b, i+1, j+1, dp);
    }
    else{
        // insert
        int insertAns = 1 + solve(a, b, i, j+1, dp);

        // delete
        int deleteAns = 1 + solve(a, b, i+1, j, dp);

        // replace
        int replaceAns = 1 + solve(a, b, i+1, j+1, dp);

        ans=  min(insertAns, min(deleteAns, replaceAns));
    }

    return dp[i][j] = ans;
}
int minDistance(string word1, string word2){
    vector<vector<int> >dp(word1.length(), vector<int>(word2.length(), -1));
    return solve(word1, word2, 0, 0, dp);
}
*/

// RECURSION
/*
int solve(string &a, string &b, int i, int j){
    if(i == a.length()){
        return b.length() - j;
    }

    if(j == b.length()){
        return a.length() - i;
    }

    int ans = 0;
    if(a[i] == b[j]){
        return solve(a, b, i+1, j+1);
    }
    else{
        int insertAns = 1 + solve(a, b, i, j+1);

        int deleteAns = 1 + solve(a, b, i+1, j);

        int replaceAns = 1 + solve(a, b, i+1, j+1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return ans;
}
int minDistance(string word1, string word2){
    return solve(word1, word2, 0, 0);
}

*/

// RECURSION + MEMOISATION
/*
int solveMem(string &a, string &b, int i, int j, vector<vector<int> >&dp){
    if(i == a.length()){
        return b.length() - j;
    }
    if(j == b.length()){
        return a.length() - i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j]){
        return solveMem(a, b, i+1, j+1, dp);
    }
    else{
        int insertAns = 1 + solveMem(a, b, i, j+1, dp);

        int deleteAns = 1 + solveMem(a, b, i+1, j, dp);

        int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);

        ans =  min(insetAns, min(deleteAns, replaceAns));
    }
    return dp[i][j] = ans;
}
int minDistance(string word1, string word2){
    vector<vector<int> >dp(word1.length() + 1, vector<int>(word2.length(), -1));
    return solve(word1, word2, 0, 0);
}
*/

// TABULATION
/*
int solveTab(string a, string b){
    vector<vector<int> >dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for(int j = 0;j < b.length();j++){
        dp[a.length()][j] == b.length() - j;
    }

    for(int i = 0;i < a.length();i++){
        dp[i][b.length()] = a.length() - i;
    }

    for(int i = a.length() - 1;i >= 0;i--){
        for(int j = b.length() - 1;j >= 0;j--){
            int ans = 0;
            if(a[i] == b[j]){
                ans = dp[i+1][j+1];
            }
            else{
                int insertAns = 1 + dp[i][j+1];

                int deleteAns = 1 + dp[i+1][j];

                int replaceAns = 1 + dp[i+1][j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int minDistance(string word1, string word2){
    return solveTab(word1, word2);
}
*/

