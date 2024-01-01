// LEETCODE 2302

/*
long long countSubarrays(vector<int>& nums, long long k){
    int i = 0;
    int j = 0;
    int count = 0;
    int sum = nums[0];
    int n = nums.size();

    while(i < n && j < n){
        if(sum < k){
            j++;
            if(j >= i){
                count+=(j-i);
            }
            if(j < n){
                sum += nums[j];
            }
        }
        else{
            sum -= nums[i];
            i++;
        }
    }
    return count;
}

*/

/*
long long countSubarrays(vector<int>& nums, long long k){
    int n = nums.size();
    int start = 0; // left pointer of the sliding window
    long long sum = 0; // sum of elements in the current window
    long long count = 0; // count od subarrays with score<k

    for(int end = 0;end < n;end++){
        sum += nums[end];

        // shrink the window form left if the sum exceeds k or equal to k

        while(sum*(end-start+1) >= k){
            sum -= nums[start];
            start++;
        }

        // The number of subarrays ending at 'end' with score<k is 'end-start + 1'

        count += (end - start + 1);
    }
    return count;

}

*/