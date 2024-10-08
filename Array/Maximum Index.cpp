// GFG POTD 5 MARCH 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
 
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int>preMin(n,0);
        vector<int>suffMax(n,0);
        
        int maxi=a[n-1];
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi, a[i]);
            suffMax[i]=maxi;
        }
        
        int mini=a[0];
        for(int i=0;i<n;i++){
            mini=min(mini, a[i]);
            preMin[i]=mini;
        }
        
        int i=0, j=0;
        int ans=-1;
        while(i<n && j<n){
            if(preMin[i]<=suffMax[j]){
                ans=max(ans, j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends



// METHOD II


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int> mini(n, 0);
        vector<int> maxi(n, 0);
        mini[0] = arr[0];
        maxi[n-1] = arr[n-1];
        for(int i = 1;i < n;i++){
            mini[i] = min(mini[i-1], arr[i]);
            maxi[n-i-1] = max(maxi[n-i], arr[n-i-1]);
        }
        int ans = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < n){
            if(mini[i] <= maxi[j]){
                ans = max(ans, j-i);
                j++;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }

};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}