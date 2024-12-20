#include<bits/stdc++.h>
using namespace std;

int n;
int solve(int i, int price[], int N, vector<vector<int>>& dp){
    if(N==0){
        return 0;
    }

    if(i == n){
        return INT_MIN;
    }

    if(dp[i][N] != -1){
        return dp[i][N];
    }

    int skip = solve(i+1, price, N, dp);
    int take = INT_MIN;

    if(N >= (i+1)){
        take = price[i] + solve(i, price, N - (i+1), dp);
    }

    return dp[i][N] = max(take, skip);
}
int cutRod(int price[], int N){
    n = N;

    vector<vector<int>> dp(N, vector<int>(N+1, -1));

    return solve(0, price, N, dp);
}