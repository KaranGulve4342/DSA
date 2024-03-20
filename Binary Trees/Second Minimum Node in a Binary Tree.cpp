// LEETCODE 671

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, set<int>& st){
        if(root == NULL) return;

        st.insert(root->val);
        inorder(root->left, st);
        inorder(root->right, st);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        inorder(root, st);

        auto it = *st.begin();
        st.erase(it);
        if(st.empty()){
            return -1;
        }
        return *st.begin();
    }
};