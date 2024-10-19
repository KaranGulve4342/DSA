// LEETCODE 1545

class Solution {
public:
    char findKthBit(int n, int k) {
        string ans = "0";

        while(true){
            if(k <= ans.length()){
                return ans[k-1];
            }
            auto str = ans;
            reverse(str.begin(), str.end());

            for(auto &ch : str){
                ch = ch=='0' ? '1' : '0';
            }

            ans += "1" + str;
        }
        return ans[k-1];
    }
};