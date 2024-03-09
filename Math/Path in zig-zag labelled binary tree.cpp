// LEETCODE 1104

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int levels = log2(label);
        vector<int> ans(levels + 1);
        ans[levels] = label;

        while(levels > 0){
            int left = pow(2, levels - 1);
            int right = pow(2, levels) - 1;

            label = left + right - (label/2);
            ans[--levels] = label;
        }
        return ans;
    }
};