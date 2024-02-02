// LEETCODE 869

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        vector<string> ans;
        for(int i = 0;i <= 30;i++){
            int ele = pow(2, i);
            ans.push_back(to_string(ele));
        }

        for(int i = 0;i <= 30;i++){
            sort(ans[i].begin(), ans[i].end());
            if(ans[i] == s){
                return true;
            }
        }

        return false;

    }
};