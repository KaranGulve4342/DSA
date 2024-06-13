// LEETCODE 424

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);

        int start = 0;
        int maxCount = 0;

        int n = s.length();
        int ans = 0;

        for(int end = 0;end < n;end++){
            counts[s[end] - 'A']++;
            if(maxCount < counts[s[end] - 'A']){
                maxCount = counts[s[end] - 'A'];
            }

            while(end - start - maxCount + 1 > k){
                counts[s[start] - 'A']--;
                start++;

                for(int i = 0;i < 26;i++){
                    if(maxCount < counts[i]){
                        maxCount = counts[i];
                    }
                }
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};