
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        int getCount (string s, int N)
        {
            unordered_map<char,long long>m;
            int n=s.size();
            m[s[n-1]]++;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]!=s[i+1])
                m[s[i]]++;
            }
            int cnt=0;
            for(auto i:m){
                if(i.second==N){
                    cnt++;
                }
            }
            return cnt;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends