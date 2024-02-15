// LEETCODE 2428

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maxSum = INT_MIN;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i < n-2;i++){
            for(int j = 0;j < m-2;j++){
                int currSum = 0;
                for(int c = j;c < j+3;c++){
                    currSum += grid[i][c];
                    currSum += grid[i+2][c];
                }
                currSum += grid[i+1][j+1];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};