// GFG POTD

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution 
{
public:
    int ways(int x, int y)
    {
        //code here.
        int mod= 1e9+7;
        vector<vector<int>> DP(x+1,vector<int>(y+1,-1));
        for (int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                //base case
                if(i==0 || j==0){
                    DP[i][j] =1;
                }
                else{
                    DP[i][j] = (DP[i-1][j] + DP[i][j-1])%mod;
                }
            }
        }
        return DP[x][y];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends