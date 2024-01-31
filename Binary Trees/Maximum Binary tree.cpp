// LEETCODE 654

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }

        auto maxIt = max_element(nums.begin(), nums.end());
        int maxIndex = distance(nums.begin(), maxIt);

        TreeNode* root = new TreeNode(*maxIt);

        vector<int> leftSubarray(nums.begin(), maxIt);
        root->left = constructMaximumBinaryTree(leftSubarray);

        vector<int> rightSubarray(maxIt + 1, nums.end());
        root->right = constructMaximumBinaryTree(rightSubarray);

        return root;
    }
};