// LEETCODE 2458

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
    int maxh;

    void preorder(TreeNode* root, vector<int>& pre, int h) {
        if (root == nullptr) return;
        pre[root->val] = maxh;
        maxh = max(maxh, h);
        preorder(root->left, pre, h + 1);
        preorder(root->right, pre, h + 1);
    }

    void postorder(TreeNode* root, vector<int>& post, int h) {
        if (root == nullptr) return;
        post[root->val] = maxh;
        maxh = max(maxh, h); 
        postorder(root->right, post, h + 1);
        postorder(root->left, post, h + 1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> pre(100001, -1); 
        vector<int> post(100001, -1);

        maxh = 0; 
        preorder(root, pre, 0);

        maxh = 0;
        postorder(root, post, 0);

        vector<int> res;
        for (int q : queries) {
            res.push_back(max(pre[q], post[q]));
        }
        return res;
    }
};