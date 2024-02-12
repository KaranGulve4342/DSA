// LEETCODE 655

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
    int height;
    int width;
    int FindHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(FindHeight(root->left), FindHeight(root->right));
    }

    void placeValue(TreeNode* root, vector<vector<string>> &ans, int row, int col){
        if(root == NULL) return;
        ans[row][col] = to_string(root->val);
        int l = col - pow(2, height-row-1);
        int r = col + pow(2, height-row-1);

        placeValue(root->left, ans, row+1, l);
        placeValue(root->right, ans, row+1, r);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        height = FindHeight(root) - 1;
        width = pow(2, height+1)-1;

        vector<vector<string>> ans(height + 1, vector<string>(width, ""));
        int row = 0;
        int col = (width - 1)/2;

        placeValue(root, ans, row, col);
        return ans;
    }
};