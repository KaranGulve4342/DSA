// LEETCODE 701

/*
class Solution{
    public:
        TreeNode* insertIntoBST(TreeNode* root,int val){
            if(root == NULL) return new TreeNode(val);
            else if(root->val > val){   // go left
                if(root->left == NULL){
                    // attach it here
                    root->left = new TreeNode(val);
                }
                else insertIntoBST(root->left,val);
            }
            else{
                if(root->right == NULL){    // go right
                    // attach it here
                    root->right = new TreeNode(val);
                }
                else insertIntoBST(root->right,val);
            }
            return root;
        }
}
*/

/*
class Solution{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root == NULL) return new TreeNode(val);
        else if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
            }
            else{
                insertIntoBST(root->left, val);
            }
        }
        else{
            if(root->right == NULL){
                root->right = new TreeNode(val);
            }
            else insertIntoBST(root->right, val);
        }

        return root;
    }
}
*/


/*
class Solution{
    public:
    void Insert(TreeNode* root,int val){
        if(root == NULL) return new TreeNode(val);
        else if(root->val > val){   // go left
            if(root->left == NULL){ 
                // attach it here
                root->left = new TreeNode(val);
            }
            else insertIntoBST(root->left,val);
        }
        else{
            if(root->right == NULL){    // go right
                // attach it here
                root->right = new TreeNode(val);
            }
            else insertIntoBST(root->right,val);
        }
    }
        TreeNode* insertIntoBST(TreeNode* root,int val){
            insert(root,val);
            if(root == NULL) return new TreeNode(val);
            return root;
        }
};
*/
