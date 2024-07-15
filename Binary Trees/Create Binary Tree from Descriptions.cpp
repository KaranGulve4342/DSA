// LEETCODE 2196

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
    TreeNode* dfs(unordered_map<int, vector<pair<int, bool>>>& parentToChildren, int root){
        TreeNode* node = new TreeNode(root);

        if(parentToChildren.find(root) != parentToChildren.end()){
            for(auto childInfo : parentToChildren[root]){
                int child = childInfo.first;
                bool isLeft = childInfo.second;

                if(isLeft){
                    node->left = dfs(parentToChildren, child);
                }
                else{
                    node->right = dfs(parentToChildren, child);
                }
            }
        }

        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, bool>>> parentToChildren;
        unordered_set<int> allNodes;
        unordered_set<int> children;

        for(auto desc : descriptions){
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            parentToChildren[parent].push_back({child, isLeft});

            allNodes.insert(parent);
            allNodes.insert(child);
            children.insert(child);
        }

        int root = 0;
        for(auto node : allNodes){
            if(children.find(node) == children.end()){
                root = node;
                break;
            }
        }

        return dfs(parentToChildren, root);
    }
};