// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        int n = S.length();
        int left = 0;
        int right = 0;
        int maxi = 0;
        
        vector<int> umap(26, 0);
        
        while(right < n){
            
            umap[S[right] - 'a']++;
            
            while(umap[S[right] - 'a'] > 1 && left <= right){
                umap[S[left] - 'a']--;
                left++;
            }
            
            if(umap[S[right] - 'a'] == 1){
                maxi = max(maxi, right - left + 1);   
            }
            right++;
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends