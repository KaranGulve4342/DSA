// LEETCODE 2641

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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void levelOrder(TreeNode* root, vector<int>& levelSum, int level){
        if(root == NULL) return;
        levelSum[level] += root->val;
        levelOrder(root->left, levelSum, level + 1);
        levelOrder(root->right, levelSum, level + 1);
    }
    void updateValues(TreeNode* root, vector<int>& levelSum, int level) {
        if (root == NULL) return;
        int sum = 0;

        if(level <= 1) root->val = 0;

        if(root->left) sum += root->left->val;
        if(root->right) sum += root->right->val;

        if(root->left) root->left->val = levelSum[level+1] - sum;
        if(root->right) root->right->val = levelSum[level+1] - sum;
        
        updateValues(root->left, levelSum, level + 1);
        updateValues(root->right, levelSum, level + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        int n = height(root);
        vector<int> levelSum(n, 0);
        levelOrder(root, levelSum, 0);
        updateValues(root, levelSum, 0);
        return root;
    }
};