// LEETCODE 111

/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftAns = minDepth(root->left);
        int rightAns = minDepth(root->right);

        if(leftAns == 0) return 1 + rightAns;
        if(rightAns == 0) return 1 + leftAns;
        
        return 1 + min(leftAns, rightAns);
    }
};
*/