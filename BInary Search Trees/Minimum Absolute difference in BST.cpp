// LEETCODE 530

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
    void inorder(TreeNode* root, vector<int>&pre){
        if(root == NULL) return;
        inorder(root->left, pre);
        pre.push_back(root->val);
        inorder(root->right, pre);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> in;

        inorder(root, in);
        int n = in.size();
        int mn = INT_MAX;
        for(int i = 1;i < n;i++){
            mn = min(mn, in[i] - in[i-1]);
        }
        return mn;

    }
};