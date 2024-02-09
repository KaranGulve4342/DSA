// LEETCODE 2415

class Solution {
public:
    void preOrder(TreeNode* p, TreeNode* q, int level){
        if(p == NULL) return;
        if(q == NULL) return;

        if(level % 2 == 0){
            swap(p->val, q->val);
        }
        preOrder(p->left, q->right, level + 1);
        preOrder(p->right, q->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        preOrder(root->left, root->right, 0);
        return root;
    }
};