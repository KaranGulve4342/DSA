// LEETCODE 144

/*
class Solution{
public:
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
}
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
        if(temp->right != NULL) st.push_back(temp->right);
        if(temp->left != NULL) st.push_back(temp->left);
    }
    return ans;
};
*/