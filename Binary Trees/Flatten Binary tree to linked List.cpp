// LEETCODE 114

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> pre;
    vector<TreeNode*> preorder(TreeNode* root){
        if(root == NULL) return pre;

        pre.push_back(root);
        preorder(root->left);
        preorder(root->right);

        return pre;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode* >pre = preorder(root);

        int n = pre.size();

        for(int i = 0;i < n-1;i++){
            pre[i]->right = pre[i+1];
            pre[i]->left = NULL;
        }
    }
};

/*
vector<TreeNode*> preorderTraversal(treeNode* root){
    vector<TreeNode*> ans;
    stack<TreeNode*> st;
    if(root != NULL) st.push(root);
    while(st.size() > 0){
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp);
        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);

    }
    return ans;
}
void flatten(TreeNode* root){
    vector<TreeNode*> ans = preorderTraversal(root);
    int n = ans.size();
    for(int i = 0;i < n-1;i++){
        ans[i]->right = ans[i+1];
        ans[i]->left = NULL;
    }
}

*/

/*
class Solution{
    public:
        void flatten(TreeNode* root){
            if(root == NULL) return;
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = NULL;
            root->right = NULL;
            flatten(l);
            flatten(r);
            root->right = l;
            TreeNode* temp = root;
            while(temp->next != NULL) temp = temp->right;
            temp->right = r;
        }
}
*/

/*
class Solution{
    public:
        void flatten(TreeNode* root){
            if(root == NULL) return;
            TreeNode* curr = root;
            while(curr != NULL){
                if(curr->left != NULL){
                    // save the right
                    TreeNode* r = curr->right;
                    curr->right = curr->left;
                    // finding pred
                    TreeNode* pred = curr->left;
                    while(pred->right != NULL) pred = pred->right;
                    // link
                    pred->right = r;
                    curr = curr->right;
                }
                else curr = curr->right;
            }
            TreeNode* temp = root;
            while(temp->right != NULL){
                temp->left = NULL;
                temp = temp->right;
            }
        }
}
*/