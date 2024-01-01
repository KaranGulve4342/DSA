// LEETCODE 103

/*
class Solution{
    public:
    vector<vector<int>>levelOrder(TreeNode* root){
        vector<vector<int>>ans;
        queue<TreeNode*> q;
        if(root == NULL) return 0;
        q.push(root);
        while(q.size() > 0){
            int n = q.size();
            vector<int>v;
            for(int i = 0;i < n;i++){
                f = q.front();
                q.pop();
                v.push_back(f->val);

                if(r->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            if(ans.size() % 2 != 0){
                reverse(temp.begin(), tem.end());
            }
            ans.push_back(temp);
        }
        return ans;

    }
};
*/

class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void levelOrder(TreeNode* root, vector< vector <int> >& ans, int level){
        if(root == NULL) return;
        ans[level].push_back(root->val);    
        levelOrder(root->left,ans, level+1);
        levelOrder(root->right,ans, level+1);   
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>>ans(n);
        levelOrder(root,ans,0);

        for(int i = 1;i < n;i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};