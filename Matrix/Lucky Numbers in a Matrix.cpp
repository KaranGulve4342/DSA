// LEETCODE 1380

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> luckyNumbers;

        for(int i = 0; i < n; i++) {
            int rowMin = INT_MAX;
            int colIndex = -1;
            
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    colIndex = j;
                }
            }
            
            bool isMaxInCol = true;
            for(int k = 0; k < n; k++) {
                if(matrix[k][colIndex] > rowMin) {
                    isMaxInCol = false;
                    break;
                }
            }

            if(isMaxInCol) {
                luckyNumbers.push_back(rowMin);
            }
        }
        return luckyNumbers;
    }
};