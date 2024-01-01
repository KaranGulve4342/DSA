// LEETCODE 1422

class Solution {
public:
    int maxScore(string s) {
        int len = s.length();
        int ones = 0;
        int tempScore = s[0] == '0'? 1 : 0;
        int score = tempScore;

        for(int i = 1;i < len - 1;i++){
            if(s[i] == '0'){
                tempScore += 1;
            }
            else{
                ones++;
                tempScore -= 1;
            }

            if(tempScore > score){
                score = tempScore;
            }
        }
        ones += (s[len - 1] == '1' ? 1 : 0);

        return ones + score;
    }
};