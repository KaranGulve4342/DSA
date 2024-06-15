/*
class Solution{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second; // sorting in ascending order
    }
    int maxMeeting(int start[], int end[], int n){
        vector<pair<int, int> > v;
        for(int i = 0;i < n;i++){
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        int count = 1;
        int ansEnd = v[0].second;

        for(int i = 1;i < n;i++){
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
}
*/

/*
class Solution{
public:
    Static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    int maxmeetings(int start[], int end[], int n){
        vector<pair<int, int> v;

        for(int i = 0;i < n;i++){
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end());

        int count = 1;
        int ansEnd = v[0].second;

        for(int i = 1;i < n;i++){
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }
        return count;
    }
}
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> ans;
        
        for(int i = 0;i < n;i++){
            ans.push_back({start[i], end[i]});
        }
        
        sort(ans.begin(), ans.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            return a.second < b.second;
        });
        
        int count = 0;
        int endTime = -1;
        
        for(auto it : ans){
            if(it.first > endTime){
                endTime = it.second;
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends