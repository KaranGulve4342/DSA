//  LEETCODE 885

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int x, int y) {
        int count = 0;

        vector<vector<int>> ans;

        int steps = 1;
        int totalCells = rows*cols;
        
        while(count < totalCells){
            for(int i = 0;i < steps;i++){
                if(x >= 0 && x < rows && y >= 0 && y < cols){
                    ans.push_back(vector<int>{x, y});
                    count++;
                }
                y++;
            }
            for(int i = 0;i < steps;i++){
                if(x >= 0 && x < rows && y >= 0 && y < cols){
                    ans.push_back(vector<int>{x, y});
                    count++;
                }
                x++;
            }
            steps++;
            for(int i = 0;i < steps;i++){
                if(x >= 0 && x < rows && y >= 0 && y < cols){
                    ans.push_back(vector<int>{x, y});
                    count++;
                }
                y--;
            }
            for(int i = 0;i < steps;i++){
                if(x >= 0 && x < rows && y >= 0 && y < cols){
                    ans.push_back(vector<int>{x, y});
                    count++;
                }
                x--;
            }
            steps++;
        }

        return ans;
    }
};