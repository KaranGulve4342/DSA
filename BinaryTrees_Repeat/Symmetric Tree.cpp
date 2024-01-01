// LEETCODE 101
/*
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;

        if(p->val != q->val) return false;

        bool leftAns = isSameTree(p->left, q->left);
        if(leftAns == false) return false;

        bool rightAns = isSametree(p->right, q->right);
        if(rightAns == false) return false;

        return true;
    }
    
    void helper(TreeNode* root){
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root){
        helper(root);
        return root;
    }
    bool isSymmetric(TreeNode* root){
        if(root == NULL) return true;

        invertTree(root->left);

        bool flag = isSametree(root->left, root->right);
        return flag;

    }
*/