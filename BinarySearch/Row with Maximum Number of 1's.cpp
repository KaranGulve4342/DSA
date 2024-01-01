#include<iostream>
#include<vector>
using namespace std;

int findMaxOnesRow(vector<vector<int>> &matrix){
    int maxOnes = 0;
    int maxOnesRow = -1;

    for(int i = 0;i < matrix.size();i++){
        int lo = 0;
        int hi = matrix[i].size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(matrix[i][mid] == 1){
                maxOnes = mid + 1;
                maxOnesRow = i;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
    }
    return maxOnesRow;
}
int main(){
    vector<vector<int>>matrix = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    int maxRow = findMaxOnesRow(matrix);
    cout<<maxRow;
}