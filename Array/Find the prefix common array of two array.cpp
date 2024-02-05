// LEETCODE 2657

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n =A.size();
        int count = 0;

        vector<int> ans;
        unordered_map<int, int> umap;

        for(int i = 0;i < n;i++){
            umap[A[i]]++;
            if(umap[A[i]] == 2){
                count++;
            }
            umap[B[i]]++;
            if(umap[B[i]] == 2){
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};