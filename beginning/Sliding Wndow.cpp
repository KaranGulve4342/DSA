// #include<iostream>
// using namespace std;
// int main(){
//     int arr[] = {7,1,2,5,8,4,9,3,6};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k = 4;
//     int maxSum = INT_MIN;
//     int maxIdx = 0;
//     int sum = 0;
//     for(int i = 0;i < k;i++){
//         sum+=arr[i];
//     }
//     maxSum = sum;
//     // sliding Window
//     int i = 1;
//     int j = k;
//     while(j < n){
//         sum = sum + arr[j] - arr[i-1];
//         if(maxSum<sum){
//             MaxSum = sum;
//             maxIdx = i;
//         }
//         i++;
//         j++;
//     }
// }

// #include<iostream>
// using namespace std;

// int main(){
//     int arr[] = {2,-3,4,4,-7,-1,4,-2,6};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0;i < n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     int k = 4;
//     int p = -1;
//     int ans[n-k+1];
//     for(int i = 0;i < k;i++){
//         if(arr[i] < 0){
//             p = i;
//             break;
//         }
//     }
//     if(p == -1) ans[0] = 1;
//     else ans[0] = arr[p];
//     // sliding Window
//     int i = 1;
//     int j = k;
//     while(j < n){
//         if(p >= i) ans[i] = arr[p];
//         else{
//             p = -1;
//             for(int x = i;x <= j;x++){
//                 if(arr[x] < 0){
//                     p = x;
//                     break;
//                 }
//             }
//             if(p!=-1) ans[i] = arr[p];
//             else{
//                 ans[i] = 1;
//             }
//         }
//         i++;
//         j++;
//     }
//     for(int l = 0;l < n-k+1;l++){
//         cout<<ans[l]<<" ";
//     }
// }

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
            len = j-i+1;
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

/*
int longestOnes(vector<int>& nums, int k){
    int n = nums.size();
    int flips = 0,i = 0,j = 0;
    int maxLen = INT_MIN, len = INT_MIN;
    while(j < n){
        if(nums[j] == 1) j++;
        else{
            // nums[j] == 0
            if(flips < k){
                flips++;
                j++;
            }
            else
            {
                // flips == k
                // calculate len
                len = j - i;
                maxLen = max(maxLen, len);
                // i ko uske aage wale 0 se ek idx aage le jaao
                while(nums[i] == 1) i++; // after this 100% nums[i] = 0
                i++;
                j++;
            }
        }
    }
    len = j-i;
    maxLen = max(maxLen, len);
    return maxLen;
}
*/

