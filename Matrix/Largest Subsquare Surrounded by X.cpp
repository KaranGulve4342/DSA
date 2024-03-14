// GFG POTD 14TH MARCH 2024

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        pair<int,int> temp[1001][1001];
        for(int i = 0;i<n;i++){
            int countX=0;
            for(int j=0;j<n;j++){
                if(a[i][j]=='X')
                countX++;
                else
                countX=0;
                temp[i][j].first=countX;
            }
        }
        for(int i = 0;i<n;i++){
            int countX=0;
            for(int j=0;j<n;j++){
                if(a[j][i]=='X')
                countX++;
                else
                countX=0;
                temp[j][i].second=countX;
            }
        }
        int maxim=0;
        for(int i= n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int sm=min(temp[i][j].first,temp[i][j].second);
                while(sm>0){
                    if(temp[i][j-sm+1].second>=sm and temp[i-sm+1][j].first>=sm){
                        break;
                    }
                    else
                    sm--;
                }
                maxim=max(maxim,sm);
                
            }
        }
        return maxim;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends