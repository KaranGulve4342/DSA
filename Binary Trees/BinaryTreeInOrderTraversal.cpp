// LEETCODE 94

// RECURSIVE APPROACH
/*
class Solution{
    public:
        void Inorder(TreeNode* root, vector<int>& ans){
            if(root == NULL) return; // base case
            Inorder(root->left,ans); // left
            ans.push_back(root->val); // root
            Inorder(root->right,ans); // right
        }
        vector<int> InorderTraversal(TreeNode* root){
            vector<int> ans;
            Inorder(root, ans);
            return ans;
        }
}
*/

// ITERATIVE APPROACH
/*
class Solution{
    public:
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> ans;
            stack<TreeNode*> st;
            TreeNode* node = root;
            while(st.size() > 0 || node){
                if(node){
                    st.push(node);
                    node = node->left;
                }
                else{   // node is null
                    TreeNode* temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    node = temp->right;
                }
            }
            return ans;
        }
};
*/



