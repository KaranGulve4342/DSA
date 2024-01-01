// LEETCODE 13

/*
class Solution {
public:
    
    int romanToInt(string s) {
        unordered_map<char,int> umap = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int ans = 0;
        int prevValue = 0;

        for(int i = s.length() - 1;i >= 0;i--){
            if(umap[s[i]] < prevValue){
                ans -= umap[s[i]];
            }
            else{
                ans += umap[s[i]];
            }
            prevValue = umap[s[i]];
        }
        return ans;

    }
};
*/