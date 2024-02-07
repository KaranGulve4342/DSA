// LEETCODE 637

class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void levelOrder(TreeNode* root, vector<vector<double>>& ans, int levels){
        if(root == NULL) return;
        ans[levels].push_back(root->val);
        levelOrder(root->left, ans, levels + 1);
        levelOrder(root->right, ans, levels + 1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        int n = levels(root);
        vector<vector<double> >ans(n, vector<double>{});

        levelOrder(root, ans, 0);

        vector<double> v;
        for(auto x : ans){
            double sum = 0;
            int count = 0;
            for(auto ele : x){
                sum += ele;
                count++;
            }
            v.push_back((double)(sum / count));
        }

        return v;
    }
};
