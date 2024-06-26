// GFG POTD

//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findOneCount(vector<vector<int>>&matrix, int row, int col){
        vector<int> delRow = {0, 1, 0, -1};
        vector<int> delCol = {1, 0, -1, 0};
        
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i < 4;i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] == 1) 
            {
                count++;
            }
        }
        return count;
    }
    int FindCoverage(vector<vector<int>>&matrix){
        // Code here
        int m = matrix.size();
        int n = matrix[0].size();
        
        int count = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 0){
                    count += findOneCount(matrix, i, j);
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		Solution obj;
		int ans = obj.FindCoverage(matrix);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends