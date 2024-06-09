// GFG

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xorr = 0;
        
        for(long long int i = 0;i < N;i++){
            xorr ^= Arr[i];
        }
        
        long long int rightmostSetBit = xorr & -xorr;
        
        long long int num1 = 0;
        long long int num2 = 0;
        
        for(long long int i = 0;i < N;i++){
            if(Arr[i] & rightmostSetBit){
                num1 ^= Arr[i];
            }
            else{
                num2 ^= Arr[i];
            }
        }
        int maxi = max(num1, num2);
        int mini = min(num1, num2);
        return {maxi, mini};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends