// LEETCODE 112

/*
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL){
            if(root->val == targetSum){
                return true;
            }
        }
        bool leftResult = hasPathSum(root->left,targetSum-(root->val));
        bool RightResult = hasPathSum(root->right,targetSum-(root->val));

        return leftResult || RightResult;
    }
};
*/