// LEETCODE 96

// TABULATION
/*
int solveTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    // i -> number of nodes
    for(int i = 2;i <= n;i++){
        // j -> node
        for(int j = 1;j <= i;j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}
int numTrees(int n){
    return solveTab(n);
}
*/

// MEMOISATION
/*
class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        int ans = 0;
        // think i as root node
        for(int i = 1;i <= n;i++){
            ans += solve(i-1, dp) * solve(n-i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n){
        vector<int> dp(n+1, -1)
        return solve(n, dp);
    }
}
*/

// RECURSION
/*
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;

        int ans = 0;
        // think i as root node
        for(int i = 1;i <= n;i++){
            ans += numTree(i-1) * numTrees(n-i);
        }
        return ans;
    }
}
*/



/*
class Solution {
public:
    vector<int> dp;
    int numTrees(int n){
        dp.clear();
        dp.resize(n+1, 0);
        dp[0] = dp[1] = 1;

        for(int i = 2;i <= n;i++){
            for(int j = 0;j < i;j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int f(int n) {
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        int sum = 0;
        for(int k = 1;k <= n;k++){
            sum += f(k-1) + f(n-k);
        }
        return dp[n] = sum;
    }
    int numTrees(int n){
        dp.clear();
        dp.resize(30,-1);
        return f(n);
    }
};

/*
class Solution {
public:
    vector<int> dp;
    int f(int i) {
        if(i == 0 || i == 1) return 1;
        if(i == 2) return 2;
        if(dp[i] != -1) return dp[i];
        int sum = 0;
        for(int k = 1;k <= n;k++){
            sum += f(k-1)*f(i-k);
        }
        return dp[i] = sum;
    }
    int numTrees(int n) {
        dp.clear();
        dp.resize(30, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i <= n;i++){
            for(int k = 1;k <= i;k++){
                dp[i] += dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }

};
*/

int main()
{
    
    
    return 0;
}


// UNIQUE BINARY SEARCH TREES
// RECURSION
/*
int numTrees(int n){
    if(n <= 1){
        return 1;
    }
    int ans = 0;
    // think i as root node
    for(int i = 1;i <= n;i++){
        ans += numTrees(i-1) * numsTrees(n-i);
    }
    return ans;
}
*/

// RECURSION + MEMOISATION

/*
int solve(int n, vector<int>& dp){
    if(n <= 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }
    
    int ans = 0;
    // think i as a root node
    for(int i = 1;i <= n;i++){
        ans += solve(i - 1, dp) * solve(n - i, dp);
    }
    return dp[n] = ans;
}

int numTrees(int n){
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}
*/

// TABULATION
/*
int solveTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    // i-> number of nodes
    for(int i = 2; i <= n;i++){
        // j -> root node
        for(int j = 1;j <= i;j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}
*/