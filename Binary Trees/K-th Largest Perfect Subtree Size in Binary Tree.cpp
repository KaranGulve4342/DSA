// LEETCODE 3319

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
    int dfs(TreeNode* root, vector<int>& v){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            v.push_back(1);
            return 1;
        }

        int leftSubTree = dfs(root->left, v);
        int rightSubTree = dfs(root->right, v);

        if(leftSubTree == INT_MIN || rightSubTree == INT_MIN){
            return INT_MIN;
        }

        if(leftSubTree == rightSubTree){
            v.push_back(leftSubTree + rightSubTree + 1);
            return leftSubTree + rightSubTree + 1;
        }

        return INT_MIN;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> v;
        v.clear();

        dfs(root, v);

        sort(v.begin(), v.end(), greater<int>());

        if(v.size() < k) return -1;

        return v[k-1];
    }
};