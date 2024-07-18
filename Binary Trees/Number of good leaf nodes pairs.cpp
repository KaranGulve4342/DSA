// LEETCODE 1530

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
    int bfs(TreeNode* start, unordered_map<TreeNode*, TreeNode*>& parent, vector<TreeNode*>& leaves, int distance){
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q;

        q.push({start, 0});

        visited.insert(start);

        int count = 0;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(dist > distance){
                break;
            }

            if(node != start && node->left == NULL && node->right == NULL){
                if(dist <= distance){
                    count++;
                }
            }

            if(node->left != NULL && visited.find(node->left) == visited.end()){
                q.push({node->left, dist + 1});
                visited.insert(node->left);
            }

            if(node->right != NULL && visited.find(node->right) == visited.end()){
                q.push({node->right, dist + 1});
                visited.insert(node->right);
            }

            if(parent[node] != NULL && visited.find(parent[node]) == visited.end()){
                q.push({parent[node], dist + 1});
                visited.insert(parent[node]);
            }
        }

        return count;
    }
    void build(TreeNode* root, TreeNode* par, unordered_map<TreeNode*, TreeNode*>&parent, vector<TreeNode*>& leaves){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            leaves.push_back(root);
        }

        parent[root] = par;

        if(root->left != NULL){
            build(root->left, root, parent, leaves);
        }
        if(root->right != NULL){
            build(root->right, root, parent, leaves);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> leaves;

        build(root, NULL, parent, leaves);

        int ans = 0;

        for(int i = 0;i < leaves.size();i++){
            ans += bfs(leaves[i], parent, leaves, distance);
        }

        return ans/2;
    }
};