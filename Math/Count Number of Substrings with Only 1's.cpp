// LEETCODE 1513

class Solution {
public:
    int numSub(string s) {
        long long n = s.length();

        long long i = 0;
        long long ans = 0;
        while(i < n){
            long long count = 0;
            while(i < n && s[i] == '1'){
                count++;
                i++;
            }
            ans += 0LL;
            ans += ((count * (count + 1))/2);
            i++;
        }
        return ans % 1000000007;
    }

};