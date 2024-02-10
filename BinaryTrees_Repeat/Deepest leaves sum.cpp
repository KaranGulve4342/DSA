// LEETCODE 1302

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
    int deepestLeavesSum(TreeNode* root) {
        int n = levels(root);
        vector<vector<int> >ans(n, vector<int>{});
        preorder(root, ans, 0);
        vector<int> v = ans[n-1];
        int sum = 0;
        for(int i = 0;i < v.size();i++){
            sum += v[i];
        }

        return sum;

    }
};