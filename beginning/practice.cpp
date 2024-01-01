/*

vector<int> productExceptSelf(vector<int> &nums){
    int n = nums.size();
    vector<int> pre(n);

    

    // prefix product array
    int p = nums[0];
    pre[0] = 1;
    for(int i = 1;i < n;i++){
        pre[i] = p;
        p*=nums[i];
    }

    // suffix product array(in prefix only)
    p = nums[n-1];
    for(int i = n - 2;i>=0;i--){
        pre[i] *= p;
        p*=nums[i];
    }
    // pre[i] = pre[i]*suf[i]
    for(int i=0;i<n;i++){
        pre[i] = pre[i]*suf[i];
    }
    return pre;
}

*/
/*
int bestClosingTime(string customers){
    int n = customers.length();
    int pre[n+1]; // no of N before kth hour
    int suf[n+1]; // no. of Y after and including kth hour
    
    pre[0] = 0;
    int Ncount = 0;
    for(int i=0;i < n;i++)
    {
        int count = 0;
        if(customers[i]=='N') Ncount++;
        pre[i+1] = pre[i] + count;
    }

}
*/
