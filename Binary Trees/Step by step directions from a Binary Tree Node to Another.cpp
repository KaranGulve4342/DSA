// LEETCODE 2096


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool generatePath(TreeNode* root, int target, string &path){
        if(root == NULL){
            return false;
        }

        if(root->val == target){
            return true;
        }

        path.push_back('L');
        if(generatePath(root->left, target, path)){
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if(generatePath(root->right, target, path)){
            return true;
        }

        path.pop_back();

        return false;
    }
    bool NodeExists(TreeNode* root, TreeNode* target){
        if(root == NULL){
            return false;
        }
        if(root == target){
            return true;
        }
        return NodeExists(root->left, target) || NodeExists(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(NodeExists(root->left, p) && NodeExists(root->left, q)){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(NodeExists(root->right, p) && NodeExists(root->right, q)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    TreeNode* findNode(TreeNode* root, int val){
        if(root == NULL){
            return NULL;
        }
        if(root->val == val){
            return root;
        }

        TreeNode* left = findNode(root->left, val);
        if(left != NULL){
            return left;
        }
        return findNode(root->right, val);
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* startNode = findNode(root, startValue);
        TreeNode* destNode = findNode(root, destValue);

        TreeNode* lca = lowestCommonAncestor(root, startNode, destNode);

        string pathToStart = "";
        generatePath(lca, startValue, pathToStart);

        string pathToDest = "";
        generatePath(lca, destValue, pathToDest);

        for(auto &c : pathToStart){
            c = 'U';
        }

        return pathToStart + pathToDest;
    }
};