// LC 1248
/*
int numberOfSubarrays(vector<int>& nums, int k){
    int n = nums.size();

    vector<int> oddIndices; // Stores the indices of odd numbers

    vector<int>prefixSum(n,0);

    int count = 0;

    // Calculate prefix Sum and store indices of odd numbers
    for(int i = 0;i < n;i++){
        prefixSum[i+1] = prefixSum[i] + (nums[i]%2);

        if(nums[i]%2 == 1){
            oddIndices.push_back(i);
        }
    }

    // Use two pointers to find valid Subarrays

    int start = 0;
    int end = k - 1;

    while(end < oddIndices.size()){
        int startOdd = oddIndices[start];
        int rightOdd = oddIndices[end];

        int startingSide = startOdd - (start > 0 ? oddIndices[start -  1] : -1);
        int endingSide = (end+1 < oddIndices.size()) ? (oddIndices[end + 1]-  endOdd) : (n - endOdd);

        count += startingSide * endingSide;

        start++;
        end++;
    }
    return count;
}
*/