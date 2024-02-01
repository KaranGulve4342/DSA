// LEETCODE 102

/*
class Solution{
    public:
        int levels(TreeNode* root){
            return 1 + max(levels(root->left),levels(root->right));
        }

        void nthLevel(TreeNode* root,int curr,int level, vector<int>& v){
            if(root == NULL) return; // base case
            if(curr == level){
                v.push_back(root->val); // root
                return;
            }
            nthLevel(root->left, curr+1, level, v); // left
            nthLevel(root->right, curr+1, level, v); // right
        }

        void levelOrder(TreeNode* root, vector<vector<int>> &ans){
            int n = levels(root);
            for(i = 1;i <= n;i++){
                vector<int> v;
                nthLevel(root,1,i,v);
                ans.push_back(v);
                cout<<endl;
            }
        }

        vector<vector<int>>levelOrder(TreeNode* root){
            vector<vector<int>> ans;
            LevelOrder(root, ans);
            return ans;
        }  
};
*/

/*
class Solution{
    public:
        int levels(TreeNode* root){
            if(root == NULL) return 0;
            return 1 + max(levels(root->left), levels(root->right));
        }

        void LevelOrder(TreeNode* root, vector<vector<int>>& ans, int level){
            if(root == NULL) return;
            ans[level].push_back(root->val);
            levelOrder(root->left, ans, level+1);
            LevelOrder(root->right, ans, level+1);
        }

        vector<vector<int>> levelOrder(TreeNode* root){
            int n = levels(root);
            vector<vector<int>>ans;
            for(int i = 1;i <= n;i++){
                vector<int> v;
                ans.push_back(v);
            }
            levelOrder(root, ans, 0);
            return ans;
        }
};
*/

/*
int levels(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void LevelOrder(TreeNode* root, vector<vector<int> >& ans, int level){
    if(root == NULL) return;
    ans[level].push_back(root->val);
    LevelOrder(root->left, ans, level+1);
    LevelOrder(root->right, ans, level+1);
}
vector<vector<int> > levelOrder(TreeNode* root){
    int n = levels(root);
    vector<vector<int> >ans;
    for(int i = 1;i <= n;i++){
        vector<int> vl
        ans.push_back(v);
    }
    levelOrder(root, ans, 0);
    return ans;
}
*/