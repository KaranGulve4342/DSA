#include<bits/stdc++.h>
using namespace std;

#define ll long long int;
vector<vector<ll> >dp;

ll f(vector<int>&wts, vector<int>&val, int idx, int W){
    if(idx == wts.size()) return 0;
    if(dp[idx][W] != -1) return dp[idx][W];
    ll ans = INT_MIN:
    // not pick
    ans = max(ans, f(wts, val, idx+1, W));
    // pick
    if(wts[idx] <= W){
        ans = max(ans, val[idx] + f(wts, val, idx+1, W-wts[idx]));
    }
    return dp[idx][W] = ans;
}
ll fbu(vector<int> &wts, vector<int> &val, int W){
    dp.resize(105, vector<ll> (100005, 0));
    int n = wts.size();
    for(int idx = n-1;idx >= 0;idx--){
        for(int j = 0;j <= N;j++){
            ll ans = INT_MIN;
            // not pick
            ans=  max(ans, dp[idx+1][j]);
            // pick
            if(wts[idx] <= W){
                ans=  max(ans, val[idx] + dp[idx+1][j-wts[idx]]);
            }
            dp[idx][j] = ans;
        }
    }
    return dp[0][W];
}
int main(){
    int n, w;
    vector<int> wts, val;
    for(int i = 0;i < n;i++){
        int w, n;
        cin>>w>>v;
        wts.push_back(w);
        val.push_back(v);
    }
    cout<<f(wts, val, 0, W)<<"\n";
    cout<<fbu(wts, val, W)<<"\n";
    return 0;
}

// RECURSION
/*
int solve(vector<int>& weight, vector<int>& value, int index, int capacity){
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solve(weight, value, index-1, capacity-weight[index]);
    }
    int exclude = 0 + solve(weight, value, index-1, capacity);

    int ans = max(exclude, include);
    return ans;
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    return solve(weight, value, n-1, maxWeight);
}
*/

// MEMOISATION
/*
int solveMem(vector<int>& weight, vector<int>& value, int index, int capacity, vector<vector<int> >&dp){
    if(index == 0){
        if(weight[0] <= capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    int include = 0;
    if(weight[index] <= capacity){
        include = value[index] + solveMem(weight, value, index-1, capacity-weight[index], dp);
    }
    int exclude = 0 + solveMem(weight, value, index-1, capacity, dp);

    dp[index][capacity] = max(exclude, include);
    return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
    return solve(weight, value, n-1, maxWeight, dp);
}

*/
// TABULATION
/*
int solveTab(vector<int>& weight, vector<int>& value, int n, int capacity){
    vector<vector<int> >dp(n, vector<int>(capacity+1, 0));

    for(int w = weight[0];w <= capacity;w++){
        if(weight[0] <= capacity) dp[0][w] = value[0];
        else dp[0][w] = 0;
    }

    for(int index = 1;index < n;index++){
        for(int w = 0;w <= capacity;w++){
            int include = 0;

            if(weight[index] <= w){
                include = value[index] + dp[index-1][w - weight[index]];
            }
            int exclude = 0 + dp[index-1][w];

            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n-1][capacity];

}
*/