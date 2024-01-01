// LEETCODE 112

/*
class Solution{
    public:
        bool hasPathSum(TreeNode* root,int sum){
            if(root == NULL){
                return false;
            }
            int newSum = sum - root->val;
            if(root->left == NULL && root->right == NULL){
                return newSum == 0;
            }
            return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
        }    
};
*/

