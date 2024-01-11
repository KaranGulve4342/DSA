// LEETCODE 1026

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
    int solve(TreeNode* root, int maxValue, int minValue){
        if(root == NULL){
            return maxValue - minValue;
        }

        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);

        return max(solve(root->left, maxValue, minValue), solve(root->right, maxValue, minValue));
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};