// LEETCODE 1894. Find the Student that Will Replace the Chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        int n = chalk.size();
        for(int i = 0;i < n;i++){
            sum += chalk[i];

            if(sum > k){
                break;
            }
        }

        k %= sum;

        for(int i = 0;i < chalk.size();i++){
            if(k < chalk[i]){
                return i;
            }

            k -= chalk[i];
        }

        return 0;
    }
};