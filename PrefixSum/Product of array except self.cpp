// Product of array except self (238)

/*
vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> pre(n);
    vector<int> suf(n);
    vector<int> ans(n);

    // prefix product array
    int p = nums[0];
    pre[0] = 1;
    for(int i = 1;i < n;i++){
        pre[i] = p;
        p *= nums[i];
    }

    // suffix product array
    p = nums[n-1];
    suf[n-1] = 1;
    for(int i = n - 2;i >= 0;i--){
        suf[i] = p;
        p *= nums[i];
    }

    // ans array
    for(int i=0;i<n;i++){
        ans[i] = pre[i]*suf[i];
    }
    return ans;
}
*/

/*
vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> pre(n);
    vector<int> suf(n);
    vector<int> ans(n);

    // prefix product array
    int p = nums[0];
    pre[0] = 1;
    for(int i = 1;i < n;i++){
        pre[i] = p;
        p *= nums[i];
    }

    // suffix product array
    p = nums[n-1];
    suf[n-1] = 1;
    for(int i = n - 2;i >= 0;i--){
        suf[i] = p;
        p *= nums[i];
    }

    // pre[i] = pre[i]*suf[i]
    for(int i=0;i<n;i++){
        pre[i] = pre[i]*suf[i];
    }
    return pre;
}
*/

/*
vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> pre(n);

    // prefix product array
    int p = nums[0];
    pre[0] = 1;
    for(int i = 1;i < n;i++){
        pre[i] = p;
        p *= nums[i];
    }

    // suffix product array(int prefix only)
    p =  nums[n-1];
    for(int i = n-2;i >= 0;i--){
        pre[i] *= p;
        p *= nums[i];
    }
    return pro;
}
*/