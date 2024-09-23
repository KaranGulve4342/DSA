// LEETCODE 987

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
    void dfs(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes){
        if(root != NULL){
            nodes[x][y].insert(root->val);
            dfs(root->left, x-1, y+1, nodes);
            dfs(root->right, x+1, y+1, nodes);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        dfs(root, 0, 0, nodes);

        vector<vector<int>> ans;

        for(auto node : nodes){
            vector<int> col;

            for(auto q : node.second){
                // col.insert(col.end(), q.second.begin(), q.second.end());

                for(auto v : q.second){
                    col.push_back(v);
                }
            }

            ans.push_back(col);
        }
        return ans;
    }
};