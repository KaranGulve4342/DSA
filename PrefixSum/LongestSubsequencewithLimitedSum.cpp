// LC 2389

/*
vector<int> answerQueries(vector<int>& nums,vector<int>& queries){
    int n = nums.size();
    int m = queries.size();
    vector<int> ans(m);
    // sort nums
    sort(nums.begin(), nums.end());
    // make nums prefix sum
    for(int i = 1;i < n;i++){
        nums[i] += nums[i - 1];
    }
    for(int i = 0;i < m;i++){
        int len = 0;
        for(int j = 0;j < n;j++){
            if(nums[j] > queries[i]) break;
            len++;
        }
        ans[i] = len;
    }
    return ans;
}
*/

/*
vector<int> answerQueries(vector<int>& nums,vector<int>& queries){
    int n = nums.size();
    int m = queries.size();
    vector<int> ans(m);
    // sort nums
    sort(nums.begin(),nums.end());
    // make nums prefix sum
    for(int i=  1;i < n;i++){
        nums[i] += nums[i-1];
    }
    for(int i = 0;i < m;i++){
        int maxLen = 0;
        // binary search
        int lo = 0;
        int hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] > queries[i]) hi = mid - 1;
            else{
                // nums[mid] <= queries[i]
                maxLen = mid + 1;
                lo = mid + 1;
            }
        }
        ans[i] = maxLen;
    }
    return ans;
}
*/