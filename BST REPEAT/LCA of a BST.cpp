// LEETCODE 235

/*
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,Treenode* q){
        if(root->val == p->val || root->val == q->val) return root;
        else if(root->val > p->val && root->val < q->val) return root;
        else if(root->val < p->val && root->val > q->val) return root;
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);
    }
}
*/

/*
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,Treenode* q){
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        else return root;
    }
}
*/