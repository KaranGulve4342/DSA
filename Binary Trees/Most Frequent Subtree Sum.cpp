// LEETCODE 508

class Solution {
public:
    int solve(TreeNode* root, unordered_map<int, int>& ans){
        if(root == nullptr){
            return 0;
        }
        int leftTree = solve(root->left, ans);
        int rightTree = solve(root->right, ans);
        
        int sum = root->val + leftTree + rightTree;
        ans[sum]++;
        
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> ans;
        solve(root, ans);
        
        int maxFreq = -1;
        vector<int> maxSums;

        for(auto x : ans){
            if(x.second > maxFreq){
                maxFreq = x.second;
                maxSums.clear();
                maxSums.push_back(x.first);
            } else if (x.second == maxFreq) {
                maxSums.push_back(x.first);
            }
        }
        return maxSums;
    }
};
