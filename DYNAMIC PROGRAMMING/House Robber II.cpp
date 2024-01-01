// CODING NINJAS

/*
long long int solve(vector<int>& nums){
    int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for(int i=1;i < n;i++){
        long long int incl=  prev2 + nums[i];
        long long int excl = prev1 + 0;

        long long int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse){
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];

    vector<int> first, second;
    for(int i = 0;i < n;i++){
        if(i != n-1) first.push_back(valueInHouse[i]);
        if(i != 0) second.push_back(valueInHouse[i]);
    }
    return max(solve(first), solve(second));
}

*/



// Using DP
/*
class Solution {
public:
    int solve(vector<int> &nums, int start, int end){
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        for (int i = start+2; i <= end; i++) {
            dp[i] = max(dp[i - 1], nums[i] + (i >= 2 ? dp[i - 2] : 0));
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int max1 = solve(nums,0, n-2);
        int max2 = solve(nums, 1, n-1);

        return max(max1, max2);
    }
};
*/



/*
long long int solve(vector<int> &nums){
    long long int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for(int i = 1;i < n;i++){
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 + 0;

        long long int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int HouseRobber(vector<int> &valueInHouse){
    int n = valueInHouse.size();

    if(n == 1) return valueInHouse[0];

    vector<int> first, second;
    for(int i = 0;i < n;i++){
        if(i != n-1) first.push_back(valueInHouse[i]);
        if(i != 0 second.push_back(valueInHouse[i]);
    }

    return max(solve(first), solve(second));
}

*/