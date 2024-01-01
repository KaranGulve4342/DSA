#include<iostream>
#include<vector> 
using namespace std;

vector<int> h; // heights
int k = 2;
vector<int> dp;
int f(int i){
    if(i >= h.size()){
        return INT_MAX;
    }
    if(i == h.size() - 1){
        // last stone
        return 0;
    }
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j = 1;j <= k;j++){
        if(i+j >= h.size()) break;
        ans = min(ans, abs(h[i] - h[i+j]) + f[i+j]);
    }
    return dp[i] = ans;
}

// bottom to up approach

int fbu(){
    int n = h.size();
    // base case
    dp.resize(100005, INT64_MAX);
    dp[n-1] = 0;
    for(int i = n-2;i >= 0;i--){
        for(int j = i;j <= k;j++){
            if(i+j >= h.size()) break;
            dp[i] = min(dp[i], abs(h[i] - h[i + j]) + dp[i+j]);
        }
    }
    return dp[0];
}

int main() {
    int n;
    cin >> n;
    h.resize(n);
    dp.resize(n, -1); // dp[i] == -1 -> ith state b=not yet computed'
    for(int i = 0;i < n;i++){
        cin>>h[i];
    }
    // cout<<f(0)<<"\n";
    cout<<fbu()<<" ";
    return 0;
}


/*
#include<bits/stdc++.h>
using namesapce std;
const int N = 1e5 + 10;

int h[N];
int dp[N];

int func(int i){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;
    // way 1
    cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));
    // way 2
    if(i > 1) cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));

    return dp[i] = cost;
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>h[i];
    }
    cout<<func(n-1);
    return 0;
}
*/