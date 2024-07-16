// GFG PRACTICE

// USING MEMOISATION

class Solution{
    public:
    /*You are required to complete below method */
    const int MOD = 1e9 + 7;
    long long int solve(int i, int j, const string str, vector<vector<long long>>& dp){
        if(i > j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(i == j){
            return dp[i][j] = 1;   
        }
        int ans = 0;
        if(str[i] == str[j]){
            ans = (1 + (solve(i+1, j, str, dp) + solve(i, j-1, str, dp)) % MOD) % MOD;
        }
        else{
            ans = ((solve(i+1, j, str, dp) + solve(i, j-1, str, dp)) % MOD - solve(i+1, j-1, str, dp)) % MOD;
        }
        
        return dp[i][j] = ans;
    }
    long long int  countPS(string str)
    {
       //Your code here
       long long int n = str.length();
       vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));
       
       return solve(0, n-1, str, dp);
    }
     
};

// USING TABULATION

class Solution{
    public:
    /*You are required to complete below method */
    const int MOD = 1e9 + 7;
    long long int countPS(string str)
    {
       //Your code here
       long long int n = str.length();
       vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
       
       for(int i = 0; i < n; i++){
           dp[i][i] = 1;
       }
       
       for(int len = 2; len <= n; len++){
           for(int i = 0; i < n; i++){
               int j = i + len - 1;
               if(j >= n){
                   break;
               }
               if(str[i] == str[j]){
                   dp[i][j] = (1 + (dp[i+1][j] + dp[i][j-1]) % MOD) % MOD;
               }
               else{
                   dp[i][j] = ((dp[i+1][j] + dp[i][j-1]) % MOD - dp[i+1][j-1]) % MOD;
               }
           }
       }
       
       return dp[0][n-1];
    }
     
};

// 