// GFG PRACTICE => KADANE'S ALGORITHM

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here 
          unordered_map<char, int> umap;
          
          for(int i = 0;i < n;i++){
              umap[x[i]] = b[i];
          }
          
          int sum = 0;
          int maxi = INT_MIN;
          
          string ans = "";
          string temp = "";
          
          for(int i = 0;i < w.length();i++){
              int ascii;
              
              if(umap.find(w[i]) != umap.end()){
                  ascii = umap[w[i]];
              }
              else{
                  ascii = (int)w[i];
              }
              
              sum += ascii;
              temp += w[i];
              
              if(sum > maxi){
                  maxi = sum;
                  ans = temp;
              }
              if(sum < 0){
                  sum = 0;
                  temp = "";
              }
          }
          
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends