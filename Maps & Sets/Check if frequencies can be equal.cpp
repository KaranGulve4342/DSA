// LEETCODE 08 MARCH 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    unordered_map<char, int> frequency;
        for(char c : s)
            frequency[c]++;
        
        unordered_map<int, int> freqCount; // To count frequencies of frequencies
        
        for(auto pair : frequency)
            freqCount[pair.second]++;
        
        if(freqCount.size() > 2){
            return false;
        }
        
        if(freqCount.size() == 1){
            return true;
        }
        
        auto it = freqCount.begin();
        int firstFreq = it->first;
        int secondFreq = (++it)->first;
        
        // Check if one of these frequencies has only one occurrence and if the difference between them is 1
        if((freqCount[firstFreq] == 1 && firstFreq == secondFreq + 1) || 
           (freqCount[secondFreq] == 1 && secondFreq == firstFreq + 1)){
            return true;
        }
        
        // Check if only one of the frequencies has one occurrence and the other frequency occurs only once more than the first one
        if((freqCount[firstFreq] == 1 && firstFreq == 1) || 
           (freqCount[secondFreq] == 1 && secondFreq == 1)){
            return true;
        }
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends