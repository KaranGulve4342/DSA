// LEETCODE 145

// RECURSIVE APPROACH
/*
class Solution{
    public:
        void postorder(TreeNode* root, vector<int>& ans){
            if(root == NULL) return; // base case
            postorder(root->left,ans); // left
            postorder(root->right,ans); // right
            ans.push_back(root->val); // root
        }
        vector<int> postorderTraversal(TreeNode* root){
            vector<int> ans;
            postorder(root, ans);
            return ans;
        }
}
*/

// ITERATIVE APPROACH
/*
class Solution{
    public:
        vector<int> postorderTraversal(TreeNode* root){
            vector<int> ans;
            stack<TreeNode*> st;
            if(root != NULL) st.push(root);
            while(st.size() > 0){
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                if(temp->left != NULL) st.push(temp->left);
                if(temp->right != NULL) st.push(temp->right);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};
*/
