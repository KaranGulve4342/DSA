#include<bits/stdc++.h>
using namespace std;

// Recursion

/*
int solve(int i, int j, vector<vector<int>>& triangle, int n){
    if(i == n-1){
        return triange[n-1][j];
    }

    int d = triange[i][j] + solve(i+1, j, triangle, n);
    int dg = triangle[i][j] + solve(i+1, j+1, triangle n);

    return min(d, dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    return solve(0, 0, triangle, n);
}
*/

// using memoisation

/*
int solve(int i, int j, vector<vector<int>>& triange, int n){
    if(i == n-1){
        return triangle[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int d = triangle[i][j] + solve(i+1, j, triangle, n, dp);
    int dg = triangle[i][j] + solve(i+1, j+1, triangle, n, dp);

    return dp[i][j] = min(d, dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(0, 0, triangle, n, dp);
}

*/

// using tabulation

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int j = 0;j < n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i = n-2;i >= 0;i--){
        for(int j = i;j >= 0;j--){
            int d = triangle[i][j] + dp[i+1][j];
            int dg = triangle[i][j] + dp[i+1][j];

            dp[i][j] = min(d, dg);
        }
    }

    return dp[0][0];
}