// GFG 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long a[], int lo, int mid, int hi){
        vector<long long> temp;
        
        int left = lo;
        int right = mid + 1;
        
        long long count = 0;
        
        while(left <= mid && right <= hi){
            if(a[left] <= a[right]){
                temp.push_back(a[left]);
                left++;
            }
            else{
                temp.push_back(a[right]);
                count += (mid - left + 1);
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(a[left]);
            left++;
        }
        
        while(right <= hi){
            temp.push_back(a[right]);
            right++;
        }
        
        for(int i = lo;i <= hi;i++){
            a[i] = temp[i-lo];
        }
        
        return count;
    }
    
    
    long long mergeSort(long long a[], int lo, int hi){
        long long count = 0;
        
        if(lo >= hi) return count;
        
        long long mid = lo + (hi-lo)/2;
        
        count += mergeSort(a, lo, mid);
        count += mergeSort(a, mid+1, hi);
        count += merge(a, lo, mid, hi);
        
        return count;
    }
    
    long long int inversionCount(long long a[], long long N)
    {
        // Your Code Here
        // long long count = 0;
        
        // for(int i = 0;i < N;i++){
        //     for(int j = i+1;j < N;j++){
        //         if(a[i] > a[j]){
        //             count++;
        //         }
        //     }
        // }
        
        // return count;
        
        return mergeSort(a, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends