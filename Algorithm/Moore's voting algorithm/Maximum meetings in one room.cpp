// GFG

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int, int>, int>> meetings;

        for (int i = 0; i < N; ++i) {
            meetings.push_back({{F[i], S[i]}, i + 1});
        }
    
        sort(meetings.begin(), meetings.end());
    
        vector<int> result;
        int prevEnd = 0;
        for (int i = 0; i < N; ++i) {
            if (meetings[i].first.second > prevEnd) {
                result.push_back(meetings[i].second);
                prevEnd = meetings[i].first.first;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends