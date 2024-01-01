/*
int numberOfNiceSubarrays(vector<int>& nums,int k){
    int count = 0;
    int left = 0;
    int oddCount = 0;
    int result = 0;

    for(int right = 0;right < nums.size();right++){
        if(nums[right] % 2 == 1){
            oddCount++;
        }

        while(oddCount > k){
            if(nums[left] % 2 == 1){
                oddCount--;
            }
            left++;
        }
        if(oddCount == k){
            count++;
        }
    }
    return count;
}
*/