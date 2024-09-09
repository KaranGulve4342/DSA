// GFG PRACTICE

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
        vector<vector<int>> ans;
         
        sort(intervals.begin(), intervals.end());
         
         
        int start = intervals[0][0];
        int prev = intervals[0][1];
        
        for(int i = 1;i < intervals.size();i++){
            int f = intervals[i][0];
            int s = intervals[i][1];
            
            if(f <= prev){
                prev = max(prev, s);
            }
            else{
                ans.push_back({start, prev});
                start = f;
                prev = s;
            }
        }
        
        ans.push_back({start, prev});
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends