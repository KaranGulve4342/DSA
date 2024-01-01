/*
#include<iostream>
using namespace std;
int main(){
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int maxSum = INT_MIN;
    int maxIdx = -1;
    for(int i=0;i<=n-k;i++){
        int sum = 0;
        for(int j = i;j<i+k;j++){
            sum += arr[j];
        }
        if(maxSum<sum){
            maxSum = sum;
            maxIdx = i;
        }
    }
    cout<<maxSum<<endl;
    cout<<maxIdx;
}
*/

/*
#include<iostream>
using namespace std;
int main(){
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int maxSum = INT_MIN;
    int maxIdx = 0;
    int sum = 0;

    // Sliding Window Algorithm
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    maxSum = sum;
    // sliding window
    int i = 1;
    int j = k;
    while(j < n){
        sum = sum + arr[j] - arr[i-1];
        if(maxSum<sum){
            maxSum = sum;
            maxIdx = i;
        }
        i++;
        j++;
    }

    cout<<maxSum<<endl;
    cout<<maxIdx;
}
*/

// Grumpy bookstore Owner   [LEETCODE 1052]

/*
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes){
    int k = minutes;
    vector<int>& arr = customers;
    int n = arr.size();
    int prevLoss = 0;
    for(int i = 0;i < k;i++){
        if(grumpy[i] == 1) prevLoss += arr[i];
    }
    int maxLoss = prevLoss;
    int maxIdx = 0;
    int i = 1;
    int j = k;
    while(j < n){
        int currLoss = prevLoss;
        if(grumpy[j] == 1) currLoss += arr[j];
        if(grumpy[i-1] == 1) currLoss -= arr[i - 1];
        if(maxLoss < currLoss){
            maxLoss = currLoss;
            maxIdx = i;
        }
        prevLoss = currLoss;
        i++;
        j++;
    }
    // filling 0s in the grumpy array window
    for(int i = maxIdx;i < maxIdx + k;i++){
        grumpy[i] = 0;
    }
    int sum = 0;
    for(int i = 0;i < n;i++){
        if(grumpy[i]==0) sum += arr[i];
    }
    return sum;
}
*/

// First negative number in every window of size k
/*
#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,-3,4,4,-7,-1,4,-2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int p = -1;
    int ans[n-k+1];
    for(int i = 0;i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    for(int i = 0;i < k;i++){
        if(arr[i] < 0){
            p = i;
            break;
        }
    }
    if(p == -1) ans[0] = 1;
    else ans[0] = arr[p];
    // sliding window
    int i = 1;
    int j = k;
    while(j < n){
        if(p >= i) ans[i] = arr[p];
        else{
            
            for(int x = i;x <= j;x++){
                if(arr[x] < 0){
                    p == x;
                    break;
                }
                if(p != -1) ans[i] = arr[p];
                else ans[i] = 1;
            }
            i++;
            j++;
        }
    }
    for(int i = 0;i < n-k+1;i++){
        cout<<ans[i]<<" ";
    }


}
*/

// Minimum size subarray sum    [LEETCODE - 209]

/*
int minSubArrayLen(int target, vector<int>& nums){
    int n = nums.size();
    int i = 0;
    int j = 0;
    int minLen = INT_MAX;
    int len;
    int sum = 0;
    while(j < n){
        sum += nums[j];
        while(sum >= target){
            len = j - i + 1;
            minLen = min(minLen,len);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if(minLen == INT_MAX) return 0;
    return minLen;
}
*/

// Max Consecutive Ones [LEETCODE 1004]

/*
int longestOnes(vector<int>& nums,int k){
    int n = nums.size();
    int flips = 0,i = 0,j = 0;
    int maxLen = INT_MIN, len = INT_MIN;
    while(j < n){
        if(nums[j] == 1) j++;
        else{
            if(flips < k){
                flips++;
                j++;
            }
            else{
                // flips = k
                // calculate len
                len = j - i;
                maxLen = max(maxLen,len);
                // i ko just uske agle wale 0 se ek idx aage le jaao
                while(nums[i] == 1) i++; // after this 100% nums[i] = 0
                i++;
            }
        }
    }
    len = j - i;
    maxLen = max(maxLen,len);
    return maxLen;
}
*/

// Longest subarray of 1's after deleting one element   [LEETCODE - 1493]
/*
int longestOnes(vector<int>& nums,int k){
    int n = nums.size();
    int k = 1;
    int flips = 0,i = 0,j = 0;
    int maxLen = INT_MIN, len = INT_MIN;
    while(j < n){
        if(nums[j] == 1) j++;
        else{
            if(flips < k){
                flips++;
                j++;
            }
            else{
                // flips = k
                // calculate len
                len = j - i;
                maxLen = max(maxLen,len);
                // i ko just uske agle wale 0 se ek idx aage le jaao
                while(nums[i] == 1) i++; // after this 100% nums[i] = 0
                i++;
            }
        }
    }
    len = j - i;
    maxLen = max(maxLen,len);
    return maxLen;
}

// IInd Solution

int longestOnes(vector<int>& nums,int k){
    int zeroPos = -1;
    int i = 0;
    int j = 0;
    int maxLen = 0;
    int count = 0;
    while(j < n){
        int prev = zeroPos;
        if(nums[j] == 0){
            count++;
            zeroPos = j;
        }
        if(count <= 1) j++;
        else{
            maxLen = max(maxLen,j-i);
            i = prev + 1;
            count--;
            j++;
        }
    }
    maxLen = max(maxLen,j-i);
    return maxLen-1;
}
*/

/*
Subarray Product Less than k [LEETCODE 713]

int numSubarrayProductLessThanK(vector<int>& nums,int k){
    int n = nums.size();
    int i = 0;
    int j = 0;
    int count = 0;
    int product = 1;
    while(j < n){
        product *= nums[j];
        while(product >= k){
            count += (j-i);
            product /= nums[i];
            i++;
        }
        j++;
    }
    while(i < n){
        count += (j-i);
        product /= nums[i];
        i++;
    }
    return count;
}
*/
