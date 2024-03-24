// LEETCODE 3090

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> umap;
        int lo = 0;
        int hi = 0;
        int ans = 0;

        while(hi < s.length()){
            umap[s[hi]]++;

            while(umap[s[hi]] > 2){
                umap[s[lo]]--;
                lo++;
            }
            
            ans = max(ans, hi - lo + 1);
            hi++;
        }
        return ans;
    }
};