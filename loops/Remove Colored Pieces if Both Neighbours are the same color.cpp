// LEETCODE 2038

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA = 0;
        int countB = 0;

        for(int i = 1;i < colors.length()-1;i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A'){
                countA++;
            }
            else if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B'){
                countB++;
            }
        }
        return countA > countB;
    }
};

int main()
{
    
    
    return 0;
}
