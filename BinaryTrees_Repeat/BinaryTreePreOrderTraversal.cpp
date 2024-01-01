// LEETCODE 144

/*
class Solution{
public:
`   void preorder(treeNode* root, vector<int>& ans){
        if(root == NULL) return; // BASE CASE
        ans.push_back(root->val);// ROOT
        preorder(root->left, ans); // LEFT
        preorder(root->right, ans); // RIGHT
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
*/