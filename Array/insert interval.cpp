// LEETCODE 57
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> ans;

        // case 1 : non overlapping case before the merge intervals
        // Compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // case 2: overlapping case and merging the intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // case 3: no overlapping of intervals after newinterval begin merges
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        vector<vector<int>> result;
        
        for(int i = 1;i < n;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            if(end >= s){
                start = min(start, s);
                end = max(end, e);
            }
            else{
                result.push_back({start, end});
                start = s;
                end = e;
            }
        }
        
        result.push_back({start, end});
        
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends