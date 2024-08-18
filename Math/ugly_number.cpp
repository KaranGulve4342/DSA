/// LEETCODE 264

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(1, 1);
        int i = 0;
        int j = 0;
        int k = 0;

        while(ans.size() < n){
            ans.push_back(min({ans[i] * 2, ans[j] * 3, ans[k] * 5}));
            if(ans.back() == ans[i] * 2){
                i++;
            }
            if(ans.back() == ans[j] * 3){
                j++;
            }
            if(ans.back() == ans[k] * 5){
                k++;
            }
        }

        return ans.back();
    }
};