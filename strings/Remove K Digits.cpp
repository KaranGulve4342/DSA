// LEETCODE 402

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";

        if(num.length() == k){
            return "0";
        }

        for(int i = 0;i < num.length();i++){
            while(ans.length() > 0 && ans.back() > num[i] && k > 0){
                ans.pop_back();
                k--;
            }
            if(ans.length() > 0 || num[i] != '0'){
                ans += num[i];
            }
        }

        while(ans.length() > 0 && k > 0){
            ans.pop_back();
            k--;
        }

        return ans.length() == 0 ? "0" : ans;
    }
};