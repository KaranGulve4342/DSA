// GFG PRACTICE

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        unordered_map<char, int> umap;
        
        if(str1.length() != str2.length()){
            return false;
        }
        
        for(auto c : str1){
            umap[c]++;
        }
        
        int count = 0;
        
        for(int i = 0;i < str2.length();i++){
            if(umap.find(str2[i]) != umap.end()){
                umap[str2[i]]--;
                
                if(umap[str2[i]] == 0){
                    umap.erase(str2[i]);
                }
            }
            else{
                count++;
            }
        }
        
        return count <= k;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends