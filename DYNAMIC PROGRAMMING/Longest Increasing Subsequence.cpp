// LEETCODE 300

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> arr;
    vector<int> dp;
    int f(int i){
        if(i == 0) return 1;
        int mx = INT_MIN:
        if(dp[i] != -1) return dp[i];
        for(int j = 0;j <= i-1;j++){
            if(arr[j] < arr[i]){
                mx = max(mx, f(j));
            }
        }
        if(mx == INT_MIN) return dp[i] = 1;
        return dp[i] = 1 + mx;
    }
}
int lengthOfLTS(vector<int> &nums){
    arr = nums;
    dp.resize(2505, -1);
    dp[0] = 1;
    int ans = INT_MIN:
    for(int i =0;i < nums.size();i++){
        ans = max(ans, f(i));
    }
    return ans;
}


int main()
{
    
    
    return 0;
}

/*
class Solution {
public:
    int solve(vector<int>& nums, int i, int prev, int &n, vector<vector<int> >&dp){
        if(i >= n) return 0;

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int take = 0;
        int skip = solve(nums, i+1, prev, n, dp);

        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(nums, i+1, i, n, dp);
        }

        return dp[i][prev + 1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
        return solve(nums, 0, -1, n, dp);
    }
};
*/

/*
class Solution{
public:
    int dp[2515];
    int lis(int i, vector<int> &a){
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j = 0;j < i;j++){
            if(a[i] > a[j]){
                ans = max(ans, lis(j, a) + 1);
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int> & nums){
        memset(dp, -1, sieof(dp));
        int ans = 0;
        for(int i = 0;i < nums.size();i++){
            ans = max(ans, lis(i, nums));
        }
        return ans;
    }
};
*/


// gfg
/*
class Solution {
public:
    int solve(int n, int a[], int curr, int prev){
        // base case
        if(curr == n){
            return 0;
        }

        // include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
            take = 1 + solve(n, a, curr + 1, curr);
        }

        // exclude
        int skip = 0 + solve(n, a, curr + 1, prev);

        return max(take, skip);
    }

    // function to find length of longest subsequence
    int longestSubsequence(int n, int a[]){
        return solve(n, a, 0, -1);
    }
};

// MEMOISATION
class Solution{
    int solveMem(int n, int a[], int curr, int prev, vector<vector<int> >&dp){
        // base case
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev + 1];
        }

        // include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
            take = 1 + solveMem(n, a, curr + 1, curr, dp);
        }

        // exclude
        int skip = 0 + solveMem(n, a, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, skip);
    }

    // function to find length of longest subsequence
    int longestSubsequence(int n, int a[]){
        vector<vector<int> >dp(n, vector<int> (n+1, -1));
        return solveMem(n, a, 0, -1, dp);
    }
}

// TABULATION
class Solution {
public:
    int solveTab(int n, int a[]) {
        vector,vector<int> >dp(n+1, vector<int> (n+1, 0));

        for(int curr = n-1; curr >= 0;curr--) {
            for(int prev = curr - 1;prev >= -1;prev--) {
                // include
                int take = 0;
                if(prev == -1 || a[curr] > a[prev]){
                    take = 1 + dp[curr + 1][curr + 1];
                }

                // exclude
                int skip = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, skip);
            }
        }
        return dp[0][0];
    }

    // function to find length  of longest increasing subsequence
    int longestSubsequence(int n, int a[]){
        return solveTab(n, a);
    }
}

// Space Optimisation
class Solution {
public:
    int solveSO(int n, int a[]){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1;curr >= 0;curr--){
            for(int prev = curr - 1;prev >= -1;prev--){
                // include
                int take = 0;
                if(prev == -1 || a[curr] > a[prev]){
                    take = 1 + nextRow[curr + 1];
                }

                // exclude
                int skip = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(take, skip);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int longestSubsequence(int n, int a[]){
        return solve(n, a);
    }

}

// SPACE optimization
class Solution{
    int solveOptimal(int n, a[]) {
        if(n == 0) return 0;

        vector<int> ans;
        ans.push_back(a[0]);

        for(int i = 1;i < n;i++){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                // find the index of just bada element in ans
                int index = lower_bound(ans.begin(), ans.end(), a[i] - ans.begin());
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

    int longestSubsequence(int n, int a[]){
        return solveSO(n, a);
    }
}
*/

// RECURSION
/*
int solve(int n, int a[], int curr, int prev){
    if(curr == 0){
        return 0;
    }
    // include
    int take = 0;
    if(prev == -1 || a[curr] > a[prev]){
        take = 1 + solve(n, a, curr + 1, curr);
    }

    // exclude
    int skip = 0 + solve(n, a, curr+1, prev);

    return max(take, skip);
}

// function to find the length of longet increasing subsequence
int longestSusbequence(int n, int a[]){
    return solve(n, a, 0, -1);
}
*/

// MEMOISATION
/*
int solveMem(int n, int a[], int curr, int prev, vector<vector<int> >& dp){
    if(curr == n){
        return 0;
    }
    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }

    // include
    int take = 0;
    if(prev == -1 || a[curr] > a[prev]){
        take = 1 + solveMem(n, a, curr+1, curr, dp);
    }

    // exclude
    int skip = 0 + solveMem(n, a, curr+1, curr, dp);

    return dp[curr][prev+1] = max(take, skip);
}
int longestSubsequence(int n, int a[]){
    vector<vector<int> >dp(n, vector<int> (n+1, -1));
    return solveMem(n,a,0,-1,dp);

}
*/

// TABULATION
/*
int solveTab(int n, int a[]){
    
    vector<vector<int> >dp(n+1, vector<int> (n+1, 0));

    for(int curr = n-1;curr >= 0;curr--){
        for(int prev = curr-1;prev >= -1;prev--){
            // include
            int take = 0;
            if(prev == -1 || a[curr] > a[prev]){
                take = 1 + dp[curr+1][curr+1];
            }

            // exclude
            int skip = 0 + dp[curr + 1][prev + 1];

            dp[curr][prev+1] = max(take, skip);
        }
    }
    return dp[0][0];
}

int longestSubsequence(int n, int a[]){
    return solveTab(n, a);
}
*/

