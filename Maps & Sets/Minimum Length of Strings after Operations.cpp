// LEETCODE 3223

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();

        int count = 0;

        unordered_map<int, int> umap;

        for(int i = 0;i < n;i++){
            umap[s[i]]++;

            if(umap[s[i]] > 2){
                count += 2;

                umap[s[i]] = umap[s[i]] - 2;
            }
        }

        return n - count;
    }
};