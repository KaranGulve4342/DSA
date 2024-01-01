// LEETCODE 741

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution {
public:
    int neg = INT_MIN;
    ll n, m; // dimentions of the input matrix
    vector<vector<int>> mat;
    ll dp[55][55][55];

    ll f(ll i, ll j, ll x, ll y){
        if(i > n || j > m || x > n || y > m || mat[i][j] == -1 || mat[x][y] == -1) return neg;
        if(i == n && j == m){
            return mat[i][j] == 1;
        }
        if(dp[i][j][x] != -1) return dp[i][j][x];
        ll result = neg;

        result = max(result, f(i+1, j, x+1, y));
        result = max(result, f(i+1, j, x, y+1));
        result = max(result, f(i, j+1, x+1, y));
        result = max(result, f(i, j+1, x, y+1));

        if(result == neg) return dp[i][j][x] = neg;
        result += (mat[i][j] == 1);
        result += (mat[x][y] == 1);

        // remove repitition
        if(i == x && j == y && mat[i][j] == 1) result--;
        return dp[i][j][x] = result;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof dp);
        mat.clear();
        mat.resize(55, vector<int> (55, 0));
        for(int i = 0;i < n;i++){
            for(int j=  0;j < m;j++){
                mat[i+1][j+1] = grid[i][j];
            }
        }
        ll ans = f(1,1,1,1);
        return ans = neg ? 0 : ans;
    }
}

int main()
{
    
    
    return 0;
}