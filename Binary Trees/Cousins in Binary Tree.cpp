// LEETCODE 993

class Solution {
public:
    TreeNode* xParent = NULL;
    TreeNode* yParent = NULL;
    int xDepth = -1;
    int yDepth = -1;
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int depth){
        if(root == NULL) return;

        if(x == root->val){
            xParent = parent;
            xDepth = depth;
        }
        else if(y == root->val){
            yParent = parent;
            yDepth = depth;
        }
        else{
            dfs(root->left, root, x, y, depth+1);
            dfs(root->right, root, x, y, depth+1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, x, y, 0);
        return ((xDepth == yDepth) && (xParent != yParent));
    }
};