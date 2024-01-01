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
                vector<int> v;
                for(int i = 0;i < n;i++){
                    f = q.front();
                    q.pop();
                    v.push_back(f->val);

                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                }
                ans.push_back(v);
            }
            return ans;
        }
}
*/