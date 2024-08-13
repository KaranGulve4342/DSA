// CSES PROBLEM SET

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

const int MOD = 1e9 + 7;

int countPaths(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& dp){
    if(i >= n || j >= n || grid[i][j] == '*'){
        return 0;
    }
    
    if(i == n-1 && j == n-1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    return dp[i][j] = (countPaths(grid, i+1, j, dp) + countPaths(grid, i, j+1, dp)) % 1000000007;
}

signed main(){
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout<<countPaths(grid, 0, 0, dp) % MOD<<endl;

    return 0;

}