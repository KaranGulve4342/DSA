// LEETCODE 880

/*
class Solution{
public:
    string decodeIndex(string s, int k){
        long long decoded_length = 0;
        int n = s.length();
        int digit;

        for(int i = 0;i < n;i++){
            if(isdigit(s[i])){
                digit = s[i] - '0';
                decoded_length *= digit;
            }
            else{
                decoded_length++;
            }
        }
        for(int i = n - 1;i >= 0;i++){
            if(isdigit(s[i])){
                digit = s[i] - '0';
                decoded_length /= digit;
                k %= decoded_length;
            }
            else{
                if(k == 0 || k == decoded_length){
                    string ans = "";
                    ans += s[i];
                    return ans;
                }
                decoded_length--;
            }
        }
        return ans;
    }
}
*/