// LEETCODE 733

class Solution{
public:
    void dfs(int i, int j, int initialColor, int newColor, vector<vector<int> >& image){
        int n = image.size();
        int m = image[0].size();

        if(i < 0 || j < 0) return;
        if(i >= n || j >= m) return;
        if(image[i][j] != initialColor) return;

        image[i][j] = newColor;

        dfs(i-1, j, initialColor, newColor, image);
        dfs(i+1, j, initialColor, newColor, image);
        dfs(i, j-1, initialColor, newColor, image);
        dfs(i, j+1, initialColor, newColor, image);
    }
    vector<vector<int> > floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int initialColor = image[sr][sc];
        if(initialColor != newColor){
            dfs(sr, sc, initialColor, newColor, image);
        }
        return image;
    }
}

/*
class Solution {
public:
    void dfs(int i, int j, int initialColor, int color, vector<vector<int> >&image){
        int n = image.size();
        int m = image[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m) return;
        if(image[i][j] != initialColor) return;

        image[i][j] = color;

        dfs(i+1, j, initialColor, color, image);
        dfs(i-1, j, initialColor, color, image);
        dfs(i, j+1, initialColor, color, image);
        dfs(i, j-1, initialColor, color, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor != color){
            dfs(sr, sc, initialColor, color, image);
        }
        return image;
    }
};
*/




#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int> >floodFill(vector<vector<int> >& image, int sr, int sc, int color){
        if(color == image[sr][sc]) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void dfs(vector<vector<int> >&image, int currRow, int currCol, int initialColor, int newColor){
        int n = image.size();
        int m = image[0].size();

        if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) {
            return; // you are outside the grid
        }

        // if the cell you landed is not of the initial Color
        if(image[currRow][currCol] != initialColor) return;

        image[currRow][currCol] = newColor;
        dfs(image, currRow+1, currCol, initialColor, newColor); // down
        dfs(image, currRow, currCol-1, initialColor, newCOlor); // left
        dfs(image, currRow-1, currCol, initialColor, newColor); // up
        dfs(image, currRow, currCol+1, initialColor, newColor); // right

    }
};


int main()
{
    
    
    return 0;
}

/*
vector<vector<int> > floodFill(vector<vector<int> >&image, int sr, int sc, int color){
    if(color == image[sr][sc]) return image;
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}
void dfs(vector<vector<int> >&image, int currRow, int currCol, int initialCOlor, int newColor){
    int n = image.size();
    int m = image[0].size();

    if(currRow < 0 || currCol < 0 || currRow >= n || currCol >= m){
        return ;
    }

    if(image[currRow][currCol] != initialColor) return;

    image[currRow][currCol] = newColor;
    dfs(image, currRow+1, currCol, initialColor, newColor); // down
    dfs(image, currRow, currCol-1, initialColor, newColor); // left
    dfs(image, currRow-1, currCol, initialColor, newColor); // up
    dfs(image, currRow, currCol+1, initialColor, newColor); // right
}

*/