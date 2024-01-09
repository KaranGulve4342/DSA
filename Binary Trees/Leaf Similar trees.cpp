// LEETCODE 872

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
    void collectLeafNodes(TreeNode* root, vector<int> &leafNodes){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            leafNodes.push_back(root->val);
        }

        collectLeafNodes(root->left, leafNodes);
        collectLeafNodes(root->right, leafNodes);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafNodes1, leafNodes2;

        collectLeafNodes(root1, leafNodes1);
        collectLeafNodes(root2, leafNodes2);

        if(leafNodes1 == leafNodes2){
            return true;
        }
        else return false;

    }
};