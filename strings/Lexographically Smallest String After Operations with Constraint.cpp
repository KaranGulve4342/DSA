// LEETCODE 3106

class Solution {
public:
    int dist_to_a(char c){
        return min(c - 'a', 'z' - c + 1);
    }
    string getSmallestString(string s, int k) {
        for(int i = 0;i < s.length();i++){
            int currdist = dist_to_a(s[i]);

            if(k >= currdist){
                k -= currdist;
                s[i] = 'a';
            }
            else{
                if(k > 0){
                    if(s[i] - k >= 'a'){
                        s[i] -= k;
                    }
                    else{
                        s[i] = 'z' - (k-1);
                    }
                    k = 0;
                }
            }
        }
        return s;
    }
};