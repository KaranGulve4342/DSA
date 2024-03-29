// LEETCODE 144

// RECURSIVE APPROACH
/*
class Solution{
    public:
        void preorder(TreeNode* root, vector<int>& ans){
            if(root == NULL) return; // base case
            ans.push_back(root->val); // root
            preorder(root->left,ans); // left
            preorder(root->right,ans); // right
        }
        vector<int> preorderTraversal(TreeNode* root){
            vector<int> ans;
            preorder(root, ans);
            return ans;
        }
}
*/

// ITERATIVE APPROACH

/*
class Solution{
    public:
        vector<int> preorderTraversal(TreeNode* root){
            vector<int> ans;
            stacj<TreeNode*> st;
            if(root != NULL) st.push(root);
            while(st.size() > 0){
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                if(temp->right != NULL) st.push(temp->right);
                if(temp->left != NULL) st.push(temp->left);
            }
            return ans;
        }
};
*/

/*
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;

    if(root != NULL) st.push(root);
    while(st.size() > 0){
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp->val);

        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
    }

    return ans;
}
*/




