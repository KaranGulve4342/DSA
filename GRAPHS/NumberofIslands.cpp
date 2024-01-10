// LEETCODE 200

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char> >&grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return;
        }

        if(grid[row][col] == '2' || grid[row][col] == '0'){
            return;
        }
        grid[row][col] = '2';

        dfs(row+1, col, grid);
        dfs(row, col+1, grid);
        dfs(row-1, col, grid);
        dfs(row, col-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        for(int row = 0;row < grid.size();row++){
            for(int col = 0;col < grid[0].size();col++){
                if(grid[row][col] == '1'){
                    dfs(row, col, grid);
                    count++;
                }
            }
        }

        return count;
    }
};


/*
int numIslands(vector<vector<char> >&grid){
    int rows = grid.size();
    int cols = grid[0].size();

    int cc = 0; // stores the number of connected components
    for(int r = 0;r < rows;r++){
        for(int c = 0;c < cols;c++){
            if(grid[r][c] == '0'){
                // it is a water body
                continue;
            }
            // new visited land piece found, i.e. new connected component
            cc++;
            grid[r][c] = '0'; // mark it visited
            queue<pair<int, int> >qu;
            qu.push({r, c}); // store the src node
            while(!qu.empty()){
                auto curr = qu.front(); // get one node from queue
                qu.pop();
                // go to all unvisited neighbours of the curr node
                int currRow = curr.first;
                int currCol = curr.second;

                // check up
                if(currRow - 1 >= 0 && grid[currRow - 1][currCol] == '1'){
                    qu.push({currRow-1, currCol});
                    grid[currRow-1][currCol] = '0';
                }

                // check down
                if(currRow + 1 < rows && grid[currRow + 1][currCol] == '1'){
                    qu.push({currRow+1, currCol});
                    grid[currRow+1][currCol] = '0';
                }

                // check left
                if(currCol - 1 >= 0 && grid[currRow][currCol - 1] == '1'){
                    qu.push({currRow, currCol-1});
                    grid[currRow][currCol-1] = '0';
                }

                // check right
                if(currCol + 1 < cols && grid[currRow][currCol+1] == '1'){
                    qu.push({currRow, currCol+1});
                    grid[currRow][currCol+1] = '0';
                }
            }

        }
    }
}
*/