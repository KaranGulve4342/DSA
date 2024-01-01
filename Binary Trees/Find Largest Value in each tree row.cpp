// LEETCODE 515
/*
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int rowMax = INT_MIN;
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                rowMax = max(rowMax, node->val);
            }
            result.push_back(rowMax);
        }
        return result;
    }
};
*/