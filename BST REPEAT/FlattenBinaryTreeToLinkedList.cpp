// LEETCODE 114

// METHOD 1
// make a preorder vector of treeNodes
/*
class Solution{
public:
    vector<TreeNode*> preorderTraversal(TreeNode* root){
        vector<TreeNode*> ans;
        stack<TreeNode*> st;
        if(root != NULL) st.push(root);
        while(st.size() > 0){
            Treen=Node* temp = st.top();
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
}
*/

// METHOD 2 - RECURSION

/*
class Solution{
public:
    void flatten(TreeNode* root){
        if(root == NULL) return;
        Treenode* l = root->left;
        TreeNode* r = root->right;
        root->left = NULL;
        root->right = NULL;
        flatten(l);
        flatten(r);
        root->right = l;
        TreeNode* temp=  root;
        while(temp->right != NULL) temp=  temp->right;
        temp->right = r;
    }
};
*/

/*
class Solution{
    public: void flatten(TreeNode* root){
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* r = root->right;
        root->right = root->left;
        root->left = NULL; // IMP
        TreeNode* temp=  root;
        while(temp->right != NULL) temp = temp->right;
        temp->right = r;
    }
};
*/

// METHOD 3 - MORRIES TRAVERSAL
//  SC = O(1)

/*
class Solution{
public:
    void flatten(TreeNode* root){
        if(root == NULL) return;
        TreeNode* curr = head;
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
                curr = curr->left;
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