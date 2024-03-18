// LEETCODE 1358

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count[3] = {0};
        int ans = 0;
        int left = 0;

        for(int right = 0;right < n;right++){
            count[s[right] - 'a']++;

            while(count[0] && count[1] && count[2]){
                ans += (n - right);

                count[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};