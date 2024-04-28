// LEETCODE 3127

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int countB = 0;
        int countW = 0;
        
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 2;j++){
                countB = 0;
                countW = 0;
                if(grid[i][j] == 'B'){
                    countB++;
                }
                else{
                    countW++;
                }
                
                if(grid[i+1][j] == 'B'){
                    countB++;
                }
                else{
                    countW++;
                }
                
                if(grid[i][j+1] == 'B'){
                    countB++;
                }
                else{
                    countW++;
                }
                
                if(grid[i+1][j+1] == 'B'){
                    countB++;
                }
                else{
                    countW++;
                }
                
                if(countB >= 3 || countW >= 3){
                    return true;
                }
                
            }
        }
        return false;
    }
};