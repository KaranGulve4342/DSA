// GFG PRACTICE

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> ans;
    void solve(int idx, int a[], unordered_map<int, string>& umap, string temp, int N){
        if(idx >= N){
            ans.push_back(temp);
            return;
        }
        
        string s = umap[a[idx]];
        
        for(int i = 0;i < s.length();i++){
            temp.push_back(s[i]);
            solve(idx + 1, a, umap, temp, N);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int, string> umap{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        ans.clear();
        if(N == 0){
            return ans;
        }
        
        solve(0, a, umap, "", N);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends