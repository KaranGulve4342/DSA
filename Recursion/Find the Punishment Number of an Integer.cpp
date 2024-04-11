// LEETCODE 2698

class Solution {
public:
    bool canPartition(string square, int target){
        if(square == "" && target == 0){
            return true;
        }
        if(target < 0){
            return false;
        }

        bool ans = false;

        for(int i = 0;i < square.length();i++){
            string left = square.substr(0, i+1);
            string right=  square.substr(i+1, square.length()+1);
            int leftNum = stoi(left);

            bool isPossible = canPartition(right, target - leftNum);

            if(isPossible){
                ans = true;
                return true;
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int sum = 0;

        for(int i = 1;i <= n;i++){
            int square = i*i;

            if(canPartition(to_string(square), i)){
                sum += square;
            }
        }
        return sum;
    }
};