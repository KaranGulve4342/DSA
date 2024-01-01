/*
int rev(int n){
    int r = 0;
    while(n > 0){
        r*=10;
        r+=(n%10);
        n/=10;
    }
    return r;
}
int countNIcePairs(vector<int>&nums){
    int n = nums.size();
    int count = 0;
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            if(nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])) count++;
        }
    }
    return count;
}
*/
/*
int rev(int n){
    int r = 0;
    while(n > 0){
        r*=10;
        r+=(n%10);
        n/=10;
    }
    return r;
}
int countNicePairs(vector<int>& nums){
    int n = nums.size();
    int count = 0;
    unordered_mapMint,int> m;
    for(int i = 0;i < n;i++){
        nums[i] -= rev(nums[i]);
    }
    for(int i = 0;i < n;i++){
        if(m.find(nums[i]) != m.end()){
            count = count%1000000007;
            count += m[nums[i]];
            m[nums[i]]++;
        }
        else m[nums[i]]++;
    }
    return count%1000000007;
}
*/
