// LEETCODE 1038
// BInary search tree to greater sum tree
/*
class Solution{
    public:
    int sum = 0;
    void reverseInorder(TreeNode* root){
        // right root left
        if(root == NULL) return;
        reverseInorder(root->right);
        root->val += sum;
        sum = root->val;
        reverseInorder(root->left);
    }
    
    TreeNode* BstToGst(TreeNode* root){
        reverseInorder(root);
        return root;
    }
};

*/