// LEETCODE 1022

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
    void dfs(TreeNode* root,int curr, int &ans){
        if(root == NULL) return;

        curr = 2 * curr + root->val;

        if(root->left == NULL && root->right == NULL){
            ans += curr;
        }

        dfs(root->left, curr, ans);
        dfs(root->right, curr, ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = 0;

        dfs(root, 0, ans);
        return ans;
    }
};