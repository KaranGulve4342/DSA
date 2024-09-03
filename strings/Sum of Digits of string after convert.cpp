// LEETCODE 1945

class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        int n = s.length();

        for(char c : s) {
            int val = (c - 'a' + 1);
            num += to_string(val);
        }

        if(k == 0){
            return stoi(num);
        }

        while(k--){
            int temp = 0;
            for(char c : num) {
                temp += (c - '0'); 
            }
            num = to_string(temp);
        }

        return stoi(num);
    }
};