// LEETCODE 948

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int lo = 0;
        int hi = tokens.size() - 1;
        int score = 0;

        sort(tokens.begin(), tokens.end());
        while(lo <= hi){
            if(tokens[lo] <= power){
                power -= tokens[lo];
                score += 1;
                lo++;
            }
            else if(score > 0 && lo < hi){
                power += tokens[hi];
                score -= 1;
                hi--;
            }
            else{
                break;
            }
        }

        return score;

    }
};