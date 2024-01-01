// Given the preorder traversal of a binary search tree, construct the BST

/*

class Solution{
    public:
        TreeNode* build(vector<int>& preorder,int prelo,int prehi,vector<int>& inorder,int inlo,int inhi){
            if(prelo > prehi) return NULL;
            TreeNode* root = new TreeNode(pre[prelo]);
            if(prelo == prehi) return root;
            int i = inlo;
            while(i <= inhi){
                if(in[i] == pre[prelo]) break;
                i++;
            }
            int leftCount = i - inlo;
            int rightCount = inhi - i;
            root->left = build(preorder,prelo + 1,prelo+leftCount,inorder,inlo,i-1);
            root->right = build(preorder, prelo+leftCount+1,prehi,inorder,i+1,inhi);
            return root;
        }

        TreeNode* bstFromPreorder(vector<int>& preorder){
            vector<int> inorder = preorder; // copy ban gayi
            sort(inorder.begin(),inorder.end());
            int n = pre.size();
            return build(pre,0,n-1,in,0,n-1);
        }       
};

*/

/*
TreeNode* Insert(TreeNode* root,int val){
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
TreeNode* bstFromPreorder(vector<int>& pre){
    TreeNode* root = new TreeNode(pre[0]);
    for(int i = 1;i < pre.size();i++){
        insert(root,pre[i]);
    }
    return root;
}
*/