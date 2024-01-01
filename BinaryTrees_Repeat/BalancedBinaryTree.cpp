// LEETCODE 110

/*
class Solution {
public:
    int Levels(TreeNode* root){
        if(root == NULL) return true;
        return 1 + max(Levels(root->left), Levels(root->right));
    }

    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;
        return abs(Levels(root->left) - Levels(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }    
};
*/