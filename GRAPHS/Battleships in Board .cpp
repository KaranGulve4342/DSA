// LEETCODE 419

class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>>& visited, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != 'X'){
            return;
        }
        visited[i][j] = true;

        dfs(board, visited, i+1, j);  
        dfs(board, visited, i-1, j); 
        dfs(board, visited, i, j+1);  
        dfs(board, visited, i, j-1);  
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j] && board[i][j] == 'X'){
                    count++;
                    dfs(board, visited, i, j);
                }
            }
        }
        return count;
    }
};