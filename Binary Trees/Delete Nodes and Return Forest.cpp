// LEETCODE 1110

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
    TreeNode* solve(TreeNode* root, unordered_set<int>& st, vector<TreeNode*> &ans) {
        if (root == nullptr) {
            return nullptr;
        }

        root->left = solve(root->left, st, ans);
        root->right = solve(root->right, st, ans);

        if (st.find(root->val) != st.end()) {
            if (root->left != nullptr) {
                ans.push_back(root->left);
            }
            if (root->right != nullptr) {
                ans.push_back(root->right);
            }
            delete root;
            return nullptr;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // unordered_set<int> st(to_delete.begin(), to_delete.end());
        unordered_set<int> st;

        for(auto it : to_delete){
            st.insert(it);
        }
        vector<TreeNode*> ans;

        root = solve(root, st, ans);

        if (root != nullptr) {
            ans.push_back(root);
        }

        return ans;
    }
};