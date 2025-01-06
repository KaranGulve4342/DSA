// LEETCODE 1769

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int> ans(n, 0);

        // for(int i = 0;i < n;i++){
        //     if(boxes[i] == '1'){
        //         for(int j = 0;j < n;j++){
        //             ans[j] += abs(j-i);
        //         }
        //     }
        // }

        int ballsToLeft = 0;
        int movesToLeft = 0;
        int ballsToRight = 0;
        int movesToRight = 0;

        for(int i = 0;i < n;i++){
            ans[i] += movesToLeft;
            ballsToLeft += (boxes[i] - '0');
            movesToLeft += ballsToLeft;

            int j = n-1-i;

            ans[j] += movesToRight;
            ballsToRight += (boxes[j] - '0');
            movesToRight += ballsToRight;
        }
        return ans;
    }
};