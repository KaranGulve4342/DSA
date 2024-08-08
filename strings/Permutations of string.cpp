// GFG PRACTICE

// EVERY PROBLEM IS SOLVABLE

// METHOD 1

#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	vector<string>find_permutation(string S){
	    vector<string> ans;
	    sort(S.begin(), S.end());
	    do{
	        ans.push_back(S);
	    }while(next_permutation(S.begin(), S.end()));
	    
	    return ans;
	}
};

int main(){
    int t;
    cin >> t;
    while(t--){

	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans){
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}


// *************************************************************************************************************
// METHOD 2

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string> ans;
	int n;
	void generatePermuations(int start, string S){
	       if(start == n){
	           ans.insert(S);
	           return;
	       }
	       
	       for(int i = start;i < n;i++){
	            swap(S[start], S[i]);
	            generatePermuations(start + 1, S);
	            swap(S[start], S[i]);
	       }
	}
	vector<string>find_permutation(string S){
	   n = S.length();
	   ans.clear();
	   
	   generatePermuations(0, S);
	   vector<string> answer(ans.begin(), ans.end());
	   return answer;
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends