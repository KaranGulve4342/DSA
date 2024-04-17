// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int merge(vector<int>& v, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int count = 0;
        
        while(left <= mid && right <= high){
            if(v[left] <= v[right]){
                temp.push_back(v[left]);
                left++;
            }
            else{
                count += (mid - left + 1);
                temp.push_back(v[right]);
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(v[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(v[right]);
            right++;
        }
        
        for(int i = low;i <= high;i++){
            v[i] = temp[i - low];
            
        }
        return count;
    }
    int mergesort(vector<int>& v, int low, int high){
        int count = 0;
        
        if(low >= high) return count;
        
        int mid = (low + high)/2;
        
        count += mergesort(v, low, mid);
        count += mergesort(v, mid + 1, high);
        count += merge(v, low, mid, high);
        
        return count;
    }
    int countPairs(int arr[] , int n ) 
    {
        vector<int> v;
        for(int i = 0;i < n;i++){
            v.push_back(i * arr[i]);
            
        }
        return mergesort(v, 0, n-1);
        
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends