// LEETCODE 1886

/*
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if (mat == target) return true;
        
        // Rotate 90 degrees clockwise 4 times
        for (int k = 0; k < 3; k++) {
            // Transpose the matrix
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            
            // Reverse each row
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
            
            if (mat == target) return true;
        }
        
        return false;
    }
};

*/