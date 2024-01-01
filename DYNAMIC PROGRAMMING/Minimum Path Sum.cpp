// LEETCODE 64

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> arr, dp;
    int n, m;
    int f(int i, int j) {
        if(i == n-1 && j == m-1) return arr[n-1][m-1];
        if(i >= n || j >= m || i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = arr[i][j] + min(f(i+1, j), f(i, j+1));
    }
    int minPathSum(vector<vector<int>>& grid){
        arr = grid;
        n = arr.size();
        m = arr[0].size();
        dp.clear();
        dp.resize(205, vector<int> (205, -1));

        return f(0,0);
    }
}

/*

*/
int main()
{
    
    
    return 0;
}