// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    int mat[5][5];

    int firstIdx;
    int secondIdx;

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cin >> mat[i][j];
            if(mat[i][j] == 1){
                firstIdx = i;
                secondIdx = j;
            }
        }
    }

    int diff = abs(firstIdx - 2) + abs(secondIdx - 2);
    cout<<diff<<endl;
    return 0;


}
