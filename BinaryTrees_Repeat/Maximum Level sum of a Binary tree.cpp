// LEETCODE 1161

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void preorder(TreeNode* root, vector<vector<int> >&ans, int levels){
        if(root == NULL) return;
        ans[levels].push_back(root->val);
        preorder(root->left, ans, levels + 1);
        preorder(root->right, ans, levels + 1);
    }
    int maxLevelSum(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n, vector<int>{});
        preorder(root, ans, 0);

        int maxSum = INT_MIN;
        int idx = -1; // Initialize idx to an invalid value
        for(int i = 0; i < ans.size(); i++) { // Iterate over indices from 0 to n-1
            int currSum = 0;
            for(auto ele : ans[i]){
                currSum += ele;
            }
            if(currSum > maxSum){
                maxSum = currSum;
                idx = i; // Update idx with the index of the maximum sum
            }
        }

        // Return the index of the level with the maximum sum
        return idx+1;
    }

};