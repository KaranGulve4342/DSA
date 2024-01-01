// LEETCODE 2742

/*
class Solution {
public:
    #define ll long long int
    vector<vector<ll>> dp;
    ll solve(vector<int>& cost, vector<int> &time, int i, int wallsRemaining){
        if(wallsRemaining <= 0) return 0;
        if(i == cost.size()) return INT_MAX;
        if(dp[i][wallsRemaining] != -1) return dp[i][wallsRemaining];
        ll take = cost[i] + solve(cost, time, i+1, wallsRemaining - time[i] - 1);
        ll skip = solve(cost, time, i+1, wallsRemaining);

        return dp[i][wallsRemaining] = min(take, skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        dp = vector<vector<ll>>(505, vector<ll>(505, -1));
        return solve(cost, time, 0, time.size());
    }
};
*/

// CODING NINJAS
// PAINTING FENCE ALGORITHM

/*
#define MOD 1000000007;

int add(int a, int b) {
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b) {
    return ( (a%MOD) * (b%MOD) )%MOD;
}
int solve(int n, int k){
    if(n == 1) return k;
    if(n == 2) return add(k, mul(k, k-1));

    int ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));
}
int numberOfWays(int n, int k){
    return solve(n, k);
}
*/

// MEMOISATION
/*
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b) {
    return ( (a%MOD) * (b%MOD) )%MOD;
}
int solve(int n, int k, vector<int>& dp){
    if(n == 1) return k;
    if(n == 2) return add(k, mul(k,k-1));

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = add(mul(solveMem(n-2, k), k-1), mul(solve(n-1, k), k-1))));
    return dp[n];
}
int numberOfWays(int n, int k){
    vector<int> dp(n+1, -1);
    return solveMem(n, k, dp);
}
*/

// USING TABULATION

/*
int solveTab(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i = 3;i <= n;i++){
        dp[i]=  add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}
int numberOfWays(int n, int k){
    return solveTab(n, k);
}
*/