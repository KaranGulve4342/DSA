// LEETOCODE 543

// Diameter of a Binary tree

/*
class Solution{
public:
    int levels(TreenOde* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void helper(TreeNode* root,int &maxDia){
        if(root == NULL) return;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(naxDia, dia);
        helper(root->left, maxDia);
        helper(root->right, maxDia);
    }
    int diameterOfBinaryTree(TreeNode* root){
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
}
*/

/*
class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(ans,l+r); 
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
*/