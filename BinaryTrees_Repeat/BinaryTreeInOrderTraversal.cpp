
// LEETCODE 144

/*
class Solution{
public:
`   void inorder(treeNode* root, vector<int>& ans){
        if(root == NULL) return; // BASE CASE
        inorder(root->left, ans); // LEFT
        ans.push_back(root->val);// ROOT
        inorder(root->right, ans); // RIGHT
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
*/
