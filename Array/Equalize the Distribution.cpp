// GFG CONTEST 25/02/2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int distributeCandies(int N, vector<int> &arr)
    {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i = 0;i < N;i++){
            mx = max(mx, arr[i]);
        }
        
        for(int i = 2;i <= mx;i++){
            int ans = 0;
            for(auto j : arr){
                if(j%i != 0){
                    int diff = i - (j%i);
                    ans += diff;
                }
            }
            mn = min(mn, ans);
        }
        
        if(mn == INT_MAX){
            return -1;
        }
        return mn;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution obj;
        cout<<obj.distributeCandies(n,arr)<<endl;
    }
}
// } Driver Code Ends