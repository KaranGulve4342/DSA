// LEETCODE 337

/*
class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL) return {0, 0};

        pair<int, int> leftSubtree = dfs(root->left);
        pair<int, int> rightSubtree = dfs(root->right);

        int rob_curr = root->val + leftSubtree.second + rightSubtree.second;
        int skip_curr = max(leftSubtree.first, leftSubtree.second) + max(rightSubtree.first, rightSubtree.second);

        return {rob_curr, skip_curr};
    }
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
};
*/