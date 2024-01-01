// LEETCODE 2265

/*
class Solution {
public:
    int ans = 0;
    int traversal(TreeNode* root, int &count){
        if(root == NULL) return 0;
        count++;
        int left = traversal(root->left, count);
        int right = traversal(root->right, count);

        return (root->val + left + right);
    }
    void solve(TreeNode* root){
        if(root == NULL) return;
        int count = 0;
        int avg = (traversal(root, count))/count;

        if(avg == root->val) ans++;
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};
*/