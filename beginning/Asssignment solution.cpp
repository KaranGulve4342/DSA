#include<iostream>
using namespace std;

int main(){
    int arr[] = {2, 8, 2, 2, 5, 5, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int maxIdx = 0;
    int sum = 0;
    int i = 0
    // Sliding Window Algorithm
    while(i < n){
        
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    // maxSum = sum;
    int count = 0; // Initialize count to 1
    // sliding window
    int i = 1;
    int j = k;
    while (j < n) {
        sum = sum + arr[j] - arr[i - 1];
  
        if ((3*maxSum) <= sum) {
            // maxSum = sum;
            maxIdx = i;
            count = count + 1;
        }
        i++;
        j++;

        // cout<<count;
    }
    cout << count << endl;
    // cout<<maxSum<<endl;
    // cout<<maxIdx;
}
