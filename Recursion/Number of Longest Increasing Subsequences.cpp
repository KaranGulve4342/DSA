// LEETCODE 673
#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& arr){
    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> count(n, 1);

    int maxi = 1;

    for(int i = 0;i < n;i++){
        for(int prev = 0;prev < i;prev++){
            if(arr[prev] < arr[i] && dp[i] < 1 + dp[prev]){
                count[i] = count[j];
                dp[i] = 1 + dp[prev];
            }
            else if(arr[prev] < arr[i] && dp[i] == 1 + dp[prev]){
                count[i] += count[j];
                dp[i] = 1 + dp[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int ans = 0;

    for(int i = 0;i < n;i++){
        if(dp[i] == maxi){
            count += count[i];
        }
    }

    return maxi;
}