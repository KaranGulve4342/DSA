// LEETCODE 1447

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        unordered_set<string> st;

        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                int k = __gcd(i, j);
                int numerator = i/k;
                int denominator = j/k;

                string s = to_string(numerator) + "/" + to_string(denominator);
                st.insert(s);
            }
        }

        for(auto x : st){
            ans.push_back(x);
        }
        return ans;
    }
};