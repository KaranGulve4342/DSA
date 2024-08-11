// GFG PRACTICE

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n){
        vector<char> lower, upper;
        
        for(int i = 0; i < n; i++){
            if(isupper(str[i])){
                upper.push_back(str[i]);
            } 
            else {
                lower.push_back(str[i]);
            }
        }
        
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        
        int l = 0, u = 0;
        
        for(int i = 0; i < n; i++){
            if(isupper(str[i])){
                str[i] = upper[u++];
            } 
            else {
                str[i] = lower[l++];
            }
        }
        
        return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends