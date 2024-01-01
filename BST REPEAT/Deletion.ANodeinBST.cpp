// LEETCODE 450

/*
class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* ios(TreeNode* root){
        TreeNode* suc = root->right;
        while(suc->left != NULL){
            suc = suc->left;
        }
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            // case 1: No child
            if(root->left == NULL && root->right == NULL) return NULL;

            // case 2: 1 child Node
            if(root->left == NULL || root->right == NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }

            // case 3: 2 child Nodes
            if(root->left != NULL && root->right != NULL){
                // replace the root with its inorder pred/suc
                // after replacing delete the pred/suc
                TreeNode* suc = ios(root);
                root->val = suc->val;
                root->right = deleteNode(root->right,suc->val)
            }
        }
        else if(root->val > key){
            // go left
            root->left = deleteNode(root->left, key);
        }
        else{
            // root->vsl < key : go right
            root->right = deleteNode(root->right, key);
        }
    }
};
*/