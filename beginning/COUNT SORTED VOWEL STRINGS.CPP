// LEETCODE 1641

/*
class Solution{
    vector<int> dp(5, 1);

    for(int i = 2;i <= n;i++){
        for(int j = 3;j >= 0;j--){
            dp[j] += dp[j+1];
        }
    }
    int ans = 0;
    for(int i = 0;i < 5;i++){
        ans += dp[i];
    }
    return ans;
}
*/