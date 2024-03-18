// LEETCODE 1247

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int countX = 0;
        int countY = 0;

        for(int i = 0;i < n;i++){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x'){
                    countX++;
                }
                else{
                    countY++;
                }
            }
        }
        if((countX + countY)%2 != 0){
            return -1;
        }
        int swaps = 0;

        swaps += (countX/2 + countY/2);

        if(countX % 2 == 1){
            swaps += 2;
        }

        return swaps;
    }
};