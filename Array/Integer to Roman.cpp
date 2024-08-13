// LEETCODE 12

class Solution {
public:
    string intToRoman(int n) {
        vector<pair<int, string>> umap = {{1000, "M"},{900, "CM"},{500, "D"},{400, "CD"},{100, "C"},{90, "XC"},{50, "L"},{40, "XL"},{10, "X"},{9, "IX"},{5, "V"},{4, "IV"},{1, "I"}};
        
        string ans = "";
        
        for(auto x : umap){
            int val = x.first;
            string roman = x.second;
            
            while(n >= val){
                ans += roman;
                n -= val;
            }
        }
        
        return ans;
    }
};